#include <exception>
#include <e2node/sctp_socket.h>
#include <gtest/gtest.h>

TEST(SctpSocketTest, TestNoConnection)
{
	e2node::sctp_socket sock;
	e2node::sock_info info("127.0.0.1", 10000);
	EXPECT_THROW({ sock.connect(info); }, std::exception);
}

TEST(SctpSocketTest, TestConectException)
{
	e2node::sctp_socket sock;
	e2node::sock_info info("127.0.0.1", 10000);
	try {
		sock.connect(info);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		SUCCEED();
		return;
	}
	FAIL();
}

TEST(SctpSocketTest, TestSendNoConnection)
{
	e2node::sctp_socket sock;
	EXPECT_THROW({ sock.send((const void *)"asdf", 4); }, std::exception);
}

TEST(SctpSocketTest, TestSendException)
{
	e2node::sctp_socket sock;
	try {
		sock.send((const void *)"asdf", 4);
	} catch (std::exception &e) {
		SUCCEED();
		return;
	}
	FAIL();
}

TEST(SctpSocketTest, TestRecvNoConnection)
{
	char buf[4];
	e2node::sctp_socket sock;
	EXPECT_THROW({ sock.recv(buf, 4); }, std::exception);
}

TEST(SctpSocketTest, TestRecvException)
{
	char buf[4];
	e2node::sctp_socket sock;
	try {
		sock.recv(buf, 4);
	} catch (std::exception &e) {
		SUCCEED();
		return;
	}
	FAIL();
}

TEST(SctpSocketTest, TestSetOptionsNoConnection)
{
	e2node::sctp_socket sock;
	EXPECT_NO_THROW({ sock.set_reuse_port(true); });
	EXPECT_NO_THROW({ sock.set_reuse_port(false); });
	EXPECT_NO_THROW({ sock.set_reuse_address(true); });
	EXPECT_NO_THROW({ sock.set_reuse_address(false); });
}

TEST(SctpSocketTest, TestBindAndSetOptions_any)
{
	e2node::sctp_socket sock;
	e2node::sock_info info("any", 3116);
	sock.bind(info);
	EXPECT_NO_THROW({ sock.set_reuse_port(true); });
	EXPECT_NO_THROW({ sock.set_reuse_port(false); });
	EXPECT_NO_THROW({ sock.set_reuse_address(true); });
	EXPECT_NO_THROW({ sock.set_reuse_address(false); });
}

TEST(SctpSocketTest, TestBindAndSetOptions_localhost)
{
	e2node::sctp_socket sock;
	e2node::sock_info info("127.0.0.1", 3116);
	sock.bind(info);
	EXPECT_NO_THROW({ sock.set_reuse_port(true); });
	EXPECT_NO_THROW({ sock.set_reuse_port(false); });
	EXPECT_NO_THROW({ sock.set_reuse_address(true); });
	EXPECT_NO_THROW({ sock.set_reuse_address(false); });
}

// Other tests need either a mockup or a server component running.
