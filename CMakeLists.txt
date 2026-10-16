cmake_minimum_required(VERSION 3.25)

project(canux
  VERSION 0.1.0
  DESCRIPTION "CAN networking library family"
  LANGUAGES CXX
)

set(CANUX_STANDALONE ${canux_IS_TOP_LEVEL})

option(CANUX_WERROR "Treat compiler warnings as errors" ${CANUX_STANDALONE})
option(CANUX_SANITIZE "Build with AddressSanitizer + UBSan" OFF)
option(CANUX_BUILD_TESTS "Build unit tests" ${CANUX_STANDALONE})
set(CANUX_CATCH2_VERSION "3.16.0" CACHE STRING
    "Catch2 version to fetch when the system has none"
)

add_library(canux_build_config INTERFACE)

target_compile_options(canux_build_config INTERFACE
  -Wall
  -Wextra
  -Wpedantic
  -Wshadow
  -Wdouble-promotion
  -Wformat=2
  -Wformat-truncation
  -Wundef
  -fno-common
  -fstack-protector-strong
  $<$<BOOL:${CANUX_WERROR}>:-Werror>
  $<$<COMPILE_LANGUAGE:CXX>:
    -Wconversion
    -Wsign-conversion
    -Wsign-compare
    -Wold-style-cast
    -Wuseless-cast
    -Wsuggest-override
    -Wnon-virtual-dtor
    -Woverloaded-virtual>)

target_compile_definitions(canux_build_config INTERFACE
  $<$<CONFIG:Debug>:_GLIBCXX_ASSERTIONS>)

target_compile_options(canux_build_config INTERFACE
  "$<$<CONFIG:Release,RelWithDebInfo,MinSizeRel>:SHELL:-U_FORTIFY_SOURCE -D_FORTIFY_SOURCE=3>")

if(CANUX_SANITIZE)
  target_compile_options(canux_build_config INTERFACE
    -fsanitize=address,undefined
    -fno-sanitize-recover=all
    -fno-omit-frame-pointer)
  target_link_options(canux_build_config INTERFACE
    -fsanitize=address,undefined)
endif()

if(CANUX_BUILD_TESTS)
  enable_testing()
  list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
  include(catch2)
endif()

add_subdirectory(canup)
