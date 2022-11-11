#ifndef __mock_sctp_socket__
#define __mock_sctp_socket__
#include <e2node/sctp_socket.h>
#include <gmock/gmock.h>

using ::testing::_;

class mock_sctp_socket : public e2node::sctp_socket
{
public:
	mock_sctp_socket() : e2node::sctp_socket() { /* Nothing */ };
	~mock_sctp_socket() { /* Nothing */ };
	MOCK_METHOD(void, connect, (const e2node::sock_info &info));
	MOCK_METHOD(void, bind, (const e2node::sock_info &info));
	MOCK_METHOD(int, send, (const void *buffer, size_t len, int flags));
	MOCK_METHOD(int, recv, (const void *buffer, size_t len, int flags));

protected:
	MOCK_METHOD(void, set_bool_opt, (int level, int optname, bool optval));
};
#endif
