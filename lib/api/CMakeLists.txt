# SPDX-License-Identifier: Apache-2.0

add_definitions(-DWASMEDGE_COMPILE_LIBRARY)
if(WASMEDGE_BUILD_AOT_RUNTIME)
  add_definitions(-DWASMEDGE_BUILD_AOT_RUNTIME)
endif()

if(WASMEDGE_BUILD_SHARED_LIB)

  wasmedge_add_library(wasmedge_c SHARED
    wasmedge.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/../../include/api/wasmedge.h
  )

  set_target_properties(wasmedge_c PROPERTIES
    PUBLIC_HEADER ${CMAKE_CURRENT_BINARY_DIR}/../../include/api/wasmedge.h
    MSVC_RUNTIME_LIBRARY "MultiThreadedDLL"
  )

  target_link_libraries(wasmedge_c
    PUBLIC
    wasmedgeVM
  )

  if (WASMEDGE_BUILD_AOT_RUNTIME)
    target_link_libraries(wasmedge_c
      PUBLIC
      wasmedgeAOT
    )
  endif()

  install(TARGETS wasmedge_c
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

endif()

if(WASMEDGE_BUILD_STATIC_LIB)

  wasmedge_add_library(wasmedge_capi_static
    wasmedge.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/../../include/api/wasmedge.h
  )

  target_link_libraries(wasmedge_capi_static
    PUBLIC
    wasmedgeVM
  )

  if (WASMEDGE_BUILD_AOT_RUNTIME)
    target_link_libraries(wasmedge_capi_static
      PUBLIC
      wasmedgeAOT
    )
  endif()

  add_custom_target(wasmedge_c_static ALL
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:utilBlake3>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:spdlog::spdlog>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:wasmedgeSystem>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:wasmedgeCommon>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:wasmedgeLoaderFileMgr>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:wasmedgeAST>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:wasmedgeLoader>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:wasmedgeValidator>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:wasmedgeInterpreter>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:wasmedgeHostModuleWasi>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:wasmedgeHostModuleWasmEdgeProcess>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:wasmedgeVM>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:wasmedgeAOT>
    COMMAND ${CMAKE_AR} -x $<TARGET_FILE:wasmedge_capi_static>
    COMMAND ${CMAKE_AR} -qcs ${CMAKE_CURRENT_BINARY_DIR}/libwasmedge_c.a *.o
    COMMAND ${CMAKE_COMMAND} -E rm -f *.o
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS 
    utilBlake3
    spdlog::spdlog
    wasmedgeSystem
    wasmedgeCommon
    wasmedgeLoaderFileMgr
    wasmedgeAST
    wasmedgeLoader
    wasmedgeValidator
    wasmedgeInterpreter
    wasmedgeHostModuleWasi
    wasmedgeHostModuleWasmEdgeProcess
    wasmedgeVM
    wasmedgeAOT
    wasmedge_capi_static
  )

endif()
