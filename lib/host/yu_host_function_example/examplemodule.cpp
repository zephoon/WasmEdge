// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#include "host/yu_host_function_example/examplemodule.h"

#include "host/yu_host_function_example/examplefunc.h"

namespace WasmEdge {
namespace Host {

/// Register your functions in module.
YuHostFuncExampleModule::YuHostFuncExampleModule()
    : ImportObject("yu_host_function_example") {
  addHostFunc("yu_host_function_example_set_class_id",
              std::make_unique<YuHostFuncExampleSetClassID>(Env));
  addHostFunc("yu_host_function_example_add_student",
              std::make_unique<YuHostFuncExampleAddStudent>(Env));
  addHostFunc("yu_host_function_example_set_class_name",
              std::make_unique<YuHostFuncExampleSetClassName>(Env));
  addHostFunc("yu_host_function_example_print",
              std::make_unique<YuHostFuncExamplePrint>(Env));
}

} // namespace Host
} // namespace WasmEdge
