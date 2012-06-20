/*
 * Copyright (C) 2009 Jian Li <jianli@chromium.org>
 * Copyright (C) 2012 Patrick Gansterer <paroga@paroga.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#include "config.h"
#include "ThreadSpecific.h"

#include "StdLibExtras.h"
#include "ThreadingPrimitives.h"

#if !USE(PTHREADS)

namespace WTF {

static Mutex& destructorsMutex()
{
    DEFINE_STATIC_LOCAL(Mutex, staticMutex, ());
    return staticMutex;
}

class ThreadSpecificKeyValue {
public:
    ThreadSpecificKeyValue(void (*destructor)(void *))
        : m_destructor(destructor)
    {
        m_tlsKey = TlsAlloc();
        if (m_tlsKey == TLS_OUT_OF_INDEXES)
            CRASH();

        MutexLocker locker(destructorsMutex());
        m_next = m_first;
        m_first = this;
    }

    ~ThreadSpecificKeyValue()
    {
        MutexLocker locker(destructorsMutex());
        ThreadSpecificKeyValue** next = &m_first;
        while (*next != this) {
            ASSERT(*next);
            next = &(*next)->m_next;
        }
        *next = (*next)->m_next;

        TlsFree(m_tlsKey);
    }

    void setValue(void* data) { TlsSetValue(m_tlsKey, data); }
    void* value() { return TlsGetValue(m_tlsKey); }

    static void callDestructors()
    {
        MutexLocker locker(destructorsMutex());
        ThreadSpecificKeyValue* next = m_first;
        while (next) {
            if (void* data = next->value())
                next->m_destructor(data);
            next = next->m_next;
        }
    }

private:
    void (*m_destructor)(void *);
    DWORD m_tlsKey;
    ThreadSpecificKeyValue* m_next;

    static ThreadSpecificKeyValue* m_first;
};

ThreadSpecificKeyValue* ThreadSpecificKeyValue::m_first = 0;

long& tlsKeyCount()
{
    static long count;
    return count;
}

DWORD* tlsKeys()
{
    static DWORD keys[kMaxTlsKeySize];
    return keys;
}

void ThreadSpecificKeyCreate(ThreadSpecificKey* key, void (*destructor)(void *))
{
    *key = new ThreadSpecificKeyValue(destructor);
}

void ThreadSpecificKeyDelete(ThreadSpecificKey key)
{
    delete key;
}

void ThreadSpecificSet(ThreadSpecificKey key, void* data)
{
    key->setValue(data);
}

void* ThreadSpecificGet(ThreadSpecificKey key)
{
    return key->value();
}

void ThreadSpecificThreadExit()
{
    for (long i = 0; i < tlsKeyCount(); i++) {
        // The layout of ThreadSpecific<T>::Data does not depend on T. So we are safe to do the static cast to ThreadSpecific<int> in order to access its data member.
        ThreadSpecific<int>::Data* data = static_cast<ThreadSpecific<int>::Data*>(TlsGetValue(tlsKeys()[i]));
        if (data)
            data->destructor(data);
    }

    ThreadSpecificKeyValue::callDestructors();
}

} // namespace WTF

#endif // !USE(PTHREADS)
