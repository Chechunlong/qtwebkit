/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSTestException.h"

#include "KURL.h"
#include "TestException.h"
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSTestException);
/* Hash table */

static const HashTableValue JSTestExceptionTableValues[] =
{
    { "name", DontDelete | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestExceptionName), (intptr_t)0, NoIntrinsic },
    { "constructor", DontEnum | ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsTestExceptionConstructor), (intptr_t)0, NoIntrinsic },
    { 0, 0, 0, 0, NoIntrinsic }
};

static const HashTable JSTestExceptionTable = { 5, 3, JSTestExceptionTableValues, 0 };
/* Hash table for constructor */

static const HashTableValue JSTestExceptionConstructorTableValues[] =
{
    { 0, 0, 0, 0, NoIntrinsic }
};

static const HashTable JSTestExceptionConstructorTable = { 1, 0, JSTestExceptionConstructorTableValues, 0 };
const ClassInfo JSTestExceptionConstructor::s_info = { "TestExceptionConstructor", &Base::s_info, &JSTestExceptionConstructorTable, 0, CREATE_METHOD_TABLE(JSTestExceptionConstructor) };

JSTestExceptionConstructor::JSTestExceptionConstructor(Structure* structure, JSDOMGlobalObject* globalObject)
    : DOMConstructorObject(structure, globalObject)
{
}

void JSTestExceptionConstructor::finishCreation(ExecState* exec, JSDOMGlobalObject* globalObject)
{
    Base::finishCreation(exec->globalData());
    ASSERT(inherits(&s_info));
    putDirect(exec->globalData(), exec->propertyNames().prototype, JSTestExceptionPrototype::self(exec, globalObject), DontDelete | ReadOnly);
}

bool JSTestExceptionConstructor::getOwnPropertySlot(JSCell* cell, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSTestExceptionConstructor, JSDOMWrapper>(exec, &JSTestExceptionConstructorTable, jsCast<JSTestExceptionConstructor*>(cell), propertyName, slot);
}

bool JSTestExceptionConstructor::getOwnPropertyDescriptor(JSObject* object, ExecState* exec, PropertyName propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSTestExceptionConstructor, JSDOMWrapper>(exec, &JSTestExceptionConstructorTable, jsCast<JSTestExceptionConstructor*>(object), propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSTestExceptionPrototypeTableValues[] =
{
    { 0, 0, 0, 0, NoIntrinsic }
};

static const HashTable JSTestExceptionPrototypeTable = { 1, 0, JSTestExceptionPrototypeTableValues, 0 };
const ClassInfo JSTestExceptionPrototype::s_info = { "TestExceptionPrototype", &Base::s_info, &JSTestExceptionPrototypeTable, 0, CREATE_METHOD_TABLE(JSTestExceptionPrototype) };

JSObject* JSTestExceptionPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSTestException>(exec, globalObject);
}

const ClassInfo JSTestException::s_info = { "TestException", &Base::s_info, &JSTestExceptionTable, 0 , CREATE_METHOD_TABLE(JSTestException) };

JSTestException::JSTestException(Structure* structure, JSDOMGlobalObject* globalObject, PassRefPtr<TestException> impl)
    : JSDOMWrapper(structure, globalObject)
    , m_impl(impl.leakRef())
{
}

void JSTestException::finishCreation(JSGlobalData& globalData)
{
    Base::finishCreation(globalData);
    ASSERT(inherits(&s_info));
}

JSObject* JSTestException::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return JSTestExceptionPrototype::create(exec->globalData(), globalObject, JSTestExceptionPrototype::createStructure(globalObject->globalData(), globalObject, globalObject->objectPrototype()));
}

void JSTestException::destroy(JSC::JSCell* cell)
{
    JSTestException* thisObject = static_cast<JSTestException*>(cell);
    thisObject->JSTestException::~JSTestException();
}

JSTestException::~JSTestException()
{
    releaseImplIfNotNull();
}

bool JSTestException::getOwnPropertySlot(JSCell* cell, ExecState* exec, PropertyName propertyName, PropertySlot& slot)
{
    JSTestException* thisObject = jsCast<JSTestException*>(cell);
    ASSERT_GC_OBJECT_INHERITS(thisObject, &s_info);
    return getStaticValueSlot<JSTestException, Base>(exec, &JSTestExceptionTable, thisObject, propertyName, slot);
}

bool JSTestException::getOwnPropertyDescriptor(JSObject* object, ExecState* exec, PropertyName propertyName, PropertyDescriptor& descriptor)
{
    JSTestException* thisObject = jsCast<JSTestException*>(object);
    ASSERT_GC_OBJECT_INHERITS(thisObject, &s_info);
    return getStaticValueDescriptor<JSTestException, Base>(exec, &JSTestExceptionTable, thisObject, propertyName, descriptor);
}

JSValue jsTestExceptionName(ExecState* exec, JSValue slotBase, PropertyName)
{
    JSTestException* castedThis = jsCast<JSTestException*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    TestException* impl = static_cast<TestException*>(castedThis->impl());
    JSValue result = jsString(exec, impl->name());
    return result;
}


JSValue jsTestExceptionConstructor(ExecState* exec, JSValue slotBase, PropertyName)
{
    JSTestException* domObject = jsCast<JSTestException*>(asObject(slotBase));
    return JSTestException::getConstructor(exec, domObject->globalObject());
}

JSValue JSTestException::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTestExceptionConstructor>(exec, jsCast<JSDOMGlobalObject*>(globalObject));
}

static inline bool isObservable(JSTestException* jsTestException)
{
    if (jsTestException->hasCustomProperties())
        return true;
    return false;
}

bool JSTestExceptionOwner::isReachableFromOpaqueRoots(JSC::Handle<JSC::Unknown> handle, void*, SlotVisitor& visitor)
{
    JSTestException* jsTestException = jsCast<JSTestException*>(handle.get().asCell());
    if (!isObservable(jsTestException))
        return false;
    UNUSED_PARAM(visitor);
    return false;
}

void JSTestExceptionOwner::finalize(JSC::Handle<JSC::Unknown> handle, void* context)
{
    JSTestException* jsTestException = static_cast<JSTestException*>(handle.get().asCell());
    DOMWrapperWorld* world = static_cast<DOMWrapperWorld*>(context);
    uncacheWrapper(world, jsTestException->impl(), jsTestException);
    jsTestException->releaseImpl();
}

JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, TestException* impl)
{
    return wrap<JSTestException>(exec, globalObject, impl);
}

TestException* toTestException(JSC::JSValue value)
{
    return value.inherits(&JSTestException::s_info) ? jsCast<JSTestException*>(asObject(value))->impl() : 0;
}

}
