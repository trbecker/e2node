#include <e2node/e2.h>
#include <gtest/gtest.h>
#include "mock_sctp_socket.h"

TEST(TestE2, SimpleTest)
{
	mock_sctp_socket socket;

	EXPECT_CALL(socket, connect(_)).Times(1);

	e2node::e2 e2(&socket);

	e2node::sock_info info("127.0.0.1", 3116);
	e2.connect(info);
}
