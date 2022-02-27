// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#pragma once

#include "common/defines.h"
#include "host/yu_host_function_example/examplebase.h"

namespace WasmEdge {
namespace Host {

class YuHostFuncExampleSetClassID
    : public YuHostFuncExample<YuHostFuncExampleSetClassID> {
public:
  YuHostFuncExampleSetClassID(YuHostFuncExampleEnvironment &HostEnv)
      : YuHostFuncExample(HostEnv) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst, uint32_t CID);
};

class YuHostFuncExampleAddStudent
    : public YuHostFuncExample<YuHostFuncExampleAddStudent> {
public:
  YuHostFuncExampleAddStudent(YuHostFuncExampleEnvironment &HostEnv)
      : YuHostFuncExample(HostEnv) {}
  Expect<uint32_t> body(Runtime::Instance::MemoryInstance *MemInst,
                        uint32_t StudentPtr, uint32_t StudentLen);
};

class YuHostFuncExampleSetClassName
    : public YuHostFuncExample<YuHostFuncExampleSetClassName> {
public:
  YuHostFuncExampleSetClassName(YuHostFuncExampleEnvironment &HostEnv)
      : YuHostFuncExample(HostEnv) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst,
                    uint32_t ClassNamePtr, uint32_t ClassNameLen);
};

class YuHostFuncExamplePrint : public YuHostFuncExample<YuHostFuncExamplePrint> {
public:
  YuHostFuncExamplePrint(YuHostFuncExampleEnvironment &HostEnv)
      : YuHostFuncExample(HostEnv) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst);
};

} // namespace Host
} // namespace WasmEdge
