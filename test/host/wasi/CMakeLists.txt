# SPDX-License-Identifier: Apache-2.0

add_executable(wasiTests
  wasi.cpp
)

add_test(wasiTests wasiTests)

target_link_libraries(wasiTests
  PRIVATE
  ssvmAST
  ssvmHostModuleWasi
  utilGoogleTest
)

target_include_directories(wasiTests
  PRIVATE
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/thirdparty
)

add_test(NAME wasiSocketTests
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/socketTests.py)

set(DEFS PORT=5566 BUF_SIZE=1024)

add_executable(TCPclient socket/TCPclient.cpp)
target_compile_definitions(TCPclient PRIVATE ${DEFS})

add_executable(TCPserver socket/TCPserver.cpp)
target_compile_definitions(TCPserver PRIVATE ${DEFS})
