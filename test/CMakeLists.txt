add_executable(test_timer_manager ../src/timer_manager.cc timer_manager.cc)
set(CMAKE_CXX_FLAGS "-DTESTING")
target_link_libraries(test_timer_manager gtest gtest_main)
