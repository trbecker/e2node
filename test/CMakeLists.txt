set(CMAKE_CXX_FLAGS "-DTESTING")

configure_file("test_runner" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file("node_config_1.yaml" ${CMAKE_BINARY_DIR} COPYONLY)

add_executable(unit_test test_main.cc timer_manager.cc value.cc sim_values.cc builder.cc
	e2node_message.cc sctp_socket.cc processor.cc e2.cc)
target_link_libraries(unit_test gmock gtest e2node sim_values pthread yaml-cpp)

if(TESTING)
target_link_libraries(unit_test gcov)
endif()
