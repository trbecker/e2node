#include <e2node/processor.h>
#include <gtest/gtest.h>
#include <thread>
#include <chrono>
#include <iostream>

#include "mock_sctp_socket.h"

using namespace std::chrono_literals;
using ::testing::_;

void stopper_thread(e2node::processor *processor)
{
	while (!processor->is_running())
		std::this_thread::sleep_for(10ms);
	processor->stop();
}

TEST(ProcessorTest, SimpleTest) {
	mock_sctp_socket socket;
	EXPECT_CALL(socket, connect(_)).Times(1);

	e2node::e2 e2impl(&socket);

	e2node::processor processor(&e2impl);
	e2node::sock_info info("127.0.0.1", 3116);
	std::thread th(stopper_thread, &processor);
	processor.start(info);
	th.join();
}
