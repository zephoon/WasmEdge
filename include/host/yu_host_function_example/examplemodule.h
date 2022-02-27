// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#pragma once

#include "host/yu_host_function_example/exampleenv.h"
#include "runtime/importobj.h"

#include <cstdint>

namespace WasmEdge {
namespace Host {

class YuHostFuncExampleModule : public Runtime::ImportObject {
public:
  YuHostFuncExampleModule();

  YuHostFuncExampleEnvironment &getEnv() { return Env; }

private:
  YuHostFuncExampleEnvironment Env;
};

} // namespace Host
} // namespace WasmEdge
