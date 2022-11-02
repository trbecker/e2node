set(CMAKE_CXX_FLAGS "-DTESTING")

configure_file("test_runner" ${CMAKE_BINARY_DIR} COPYONLY)

add_executable(timer_manager_test ../src/timer_manager.cc timer_manager.cc)
target_link_libraries(timer_manager_test gtest pthread)

add_executable(value_test ../src/value.cc ../src/value_generator.cc value.cc)
target_link_libraries(value_test gtest pthread)

add_executable(sim_value_test sim_values.cc)
target_link_libraries(sim_value_test sim_values e2node gtest pthread)

add_executable(node_builder_test builder.cc)
target_link_libraries(node_builder_test gtest sim_values e2node pthread yaml-cpp)
configure_file("node_config_1.yaml" ${CMAKE_BINARY_DIR} COPYONLY)

if(TESTING)
target_link_libraries(timer_manager_test gcov)
target_link_libraries(value_test gcov)
target_link_libraries(sim_value_test gcov)
target_link_libraries(node_builder_test gcov)
endif()
