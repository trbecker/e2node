#include <e2node/processor.h>
#include <gtest/gtest.h>
#include <thread>
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

void stopper_thread(e2node::processor *processor)
{
	std::cout << "Waiting for the trhad to run" << std::endl;
	while (!processor->is_running())
		std::this_thread::sleep_for(10ms);
	std::cout << "Thread detected running" << std::endl;
	processor->stop();
}

TEST(ProcessorTest, SimpleTest) {
	e2node::processor processor;
	std::thread th(stopper_thread, &processor);
	std::cout << "About to run the process" << std::endl;
	processor.run();
	th.join();
}
