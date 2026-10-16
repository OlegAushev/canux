add_executable(canup-tests
  test_canup.cpp
)

target_link_libraries(canup-tests PRIVATE
  canux::canup
  Catch2::Catch2WithMain
  canux_build_config
)

catch_discover_tests(canup-tests)
