/*
 *  Copyright (C) 2015 Canon Inc. All rights reserved.
 *  Copyright (C) 2016 Apple Inc. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "config.h"
#include "JSReadableStreamPrivateConstructors.h"

#if ENABLE(STREAMS_API)

#include "JSDOMBinding.h"
#include "JSDOMConstructor.h"
#include "JSReadableByteStreamController.h"
#include "JSReadableStream.h"
#include "JSReadableStreamDefaultController.h"
#include "JSReadableStreamDefaultReader.h"
#include "ReadableByteStreamInternalsBuiltins.h"
#include "ReadableStreamInternalsBuiltins.h"
#include "WebCoreJSClientData.h"

using namespace JSC;

namespace WebCore {

// Public JS ReadableStreamReader and ReadableStreamDefaultController constructor callbacks.
EncodedJSValue JSC_HOST_CALL constructJSReadableStreamDefaultController(ExecState& exec)
{
    VM& vm = exec.vm();
    auto scope = DECLARE_THROW_SCOPE(vm);
    return throwVMTypeError(&exec, scope, ASCIILiteral("ReadableStreamDefaultController constructor should not be called directly"));
}

// Public JS ReadableByteStreamController constructor callback.
EncodedJSValue JSC_HOST_CALL constructJSReadableByteStreamController(ExecState& exec)
{
    VM& vm = exec.vm();
    auto scope = DECLARE_THROW_SCOPE(vm);
    return throwVMTypeError(&exec, scope, ASCIILiteral("ReadableByteStreamController constructor should not be called directly"));
}

EncodedJSValue JSC_HOST_CALL constructJSReadableStreamDefaultReader(ExecState& exec)
{
    JSVMClientData& clientData = *static_cast<JSVMClientData*>(exec.vm().clientData);
    JSDOMGlobalObject& globalObject = *static_cast<JSDOMGlobalObject*>(exec.lexicalGlobalObject());

    JSC::JSObject* constructor = JSC::asObject(globalObject.get(&exec, clientData.builtinNames().ReadableStreamDefaultReaderPrivateName()));
    ConstructData constructData;
    ConstructType constructType = constructor->methodTable()->getConstructData(constructor, constructData);
    ASSERT(constructType != ConstructType::None);

    MarkedArgumentBuffer args;
    args.append(exec.argument(0));
    return JSValue::encode(JSC::construct(&exec, constructor, constructType, constructData, args));
}

// Private JS ReadableStreamDefaultReader and ReadableStreamDefaultController constructors.
using JSBuiltinReadableStreamDefaultReaderPrivateConstructor = JSBuiltinConstructor<JSReadableStreamDefaultReader>;
using JSBuiltinReadableStreamDefaultControllerPrivateConstructor =  JSBuiltinConstructor<JSReadableStreamDefaultController>;
// Private JS ReadableByteStreamController constructor.
using JSBuiltinReadableByteStreamControllerPrivateConstructor = JSBuiltinConstructor<JSReadableByteStreamController>;

STATIC_ASSERT_IS_TRIVIALLY_DESTRUCTIBLE(JSBuiltinReadableStreamDefaultReaderPrivateConstructor);
STATIC_ASSERT_IS_TRIVIALLY_DESTRUCTIBLE(JSBuiltinReadableStreamDefaultControllerPrivateConstructor);
STATIC_ASSERT_IS_TRIVIALLY_DESTRUCTIBLE(JSBuiltinReadableByteStreamControllerPrivateConstructor);

template<> const ClassInfo JSBuiltinReadableStreamDefaultReaderPrivateConstructor::s_info = { "ReadableStreamDefaultReaderPrivateConstructor", &Base::s_info, 0, CREATE_METHOD_TABLE(JSBuiltinReadableStreamDefaultReaderPrivateConstructor) };
template<> const ClassInfo JSBuiltinReadableStreamDefaultControllerPrivateConstructor::s_info = { "ReadableStreamDefaultControllerPrivateConstructor", &Base::s_info, 0, CREATE_METHOD_TABLE(JSBuiltinReadableStreamDefaultControllerPrivateConstructor) };
template<> const ClassInfo JSBuiltinReadableByteStreamControllerPrivateConstructor::s_info = { "ReadableByteStreamControllerPrivateConstructor", &Base::s_info, 0, CREATE_METHOD_TABLE(JSBuiltinReadableByteStreamControllerPrivateConstructor) };

template<> FunctionExecutable* JSBuiltinReadableStreamDefaultReaderPrivateConstructor::initializeExecutable(JSC::VM& vm)
{
    return readableStreamInternalsPrivateInitializeReadableStreamDefaultReaderCodeGenerator(vm);
}

template<> FunctionExecutable* JSBuiltinReadableStreamDefaultControllerPrivateConstructor::initializeExecutable(JSC::VM& vm)
{
    return readableStreamInternalsPrivateInitializeReadableStreamDefaultControllerCodeGenerator(vm);
}

template<> FunctionExecutable* JSBuiltinReadableByteStreamControllerPrivateConstructor::initializeExecutable(JSC::VM& vm)
{
    return readableByteStreamInternalsPrivateInitializeReadableByteStreamControllerCodeGenerator(vm);
}

JSObject* createReadableStreamDefaultReaderPrivateConstructor(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSBuiltinReadableStreamDefaultReaderPrivateConstructor::create(vm, JSBuiltinReadableStreamDefaultReaderPrivateConstructor::createStructure(vm, globalObject, globalObject.objectPrototype()), globalObject);
}

JSObject* createReadableStreamDefaultControllerPrivateConstructor(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSBuiltinReadableStreamDefaultControllerPrivateConstructor::create(vm, JSBuiltinReadableStreamDefaultControllerPrivateConstructor::createStructure(vm, globalObject, globalObject.objectPrototype()), globalObject);
}

JSObject* createReadableByteStreamControllerPrivateConstructor(VM& vm, JSDOMGlobalObject& globalObject)
{
    return JSBuiltinReadableByteStreamControllerPrivateConstructor::create(vm, JSBuiltinReadableByteStreamControllerPrivateConstructor::createStructure(vm, globalObject, globalObject.objectPrototype()), globalObject);
}

} // namespace WebCore

#endif
