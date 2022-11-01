set(CMAKE_CXX_FLAGS "-DTESTING")

add_executable(timer_manager_test ../src/timer_manager.cc timer_manager.cc)
target_link_libraries(timer_manager_test gtest)

add_executable(value_test ../src/value.cc ../src/value_generator.cc value.cc)
target_link_libraries(value_test gtest)

add_executable(sim_value_test sim_values.cc)
target_link_libraries(sim_value_test gtest)
target_link_libraries(sim_value_test sim_values)
target_link_libraries(sim_value_test e2node)

add_executable(node_builder_test builder.cc)
target_link_libraries(node_builder_test gtest)
target_link_libraries(node_builder_test yaml-cpp)
target_link_libraries(node_builder_test sim_values)
target_link_libraries(node_builder_test e2node)
configure_file("node_config_1.yaml" ${CMAKE_BINARY_DIR} COPYONLY)
