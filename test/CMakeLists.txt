set(CMAKE_CXX_FLAGS "-DTESTING")

add_executable(test_timer_manager ../src/timer_manager.cc timer_manager.cc)
target_link_libraries(test_timer_manager gtest)

add_executable(value_test ../src/value.cc ../src/value_generator.cc value.cc)
target_link_libraries(value_test gtest)

