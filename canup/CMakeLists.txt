add_library(canup
  src/canup.cpp
)

add_library(canux::canup ALIAS canup)

target_include_directories(canup PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(canup PUBLIC cxx_std_23)

target_link_libraries(canup PRIVATE canux_build_config)

if(CANUX_BUILD_TESTS)
  add_subdirectory(tests)
endif()
