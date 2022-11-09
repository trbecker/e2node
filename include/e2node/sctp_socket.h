#ifndef __e2node_sctp_socket__
#define __e2node_sctp_socket__
#include <string>

namespace e2node {
class sctp_socket {
public:
	static const std::string addr_any;

	sctp_socket();
	virtual ~sctp_socket();
	void connect(const std::string &address, const int port);
	int send(const void *buffer, size_t len, int flags=0);
	int recv(void *buffer, size_t len, int flags=0);
	void set_reuse_port(bool reuse);
	void set_reuse_address(bool reuse);
	void bind(const std::string &address, int port);

private:
	int _socket;
	bool up;

	void create();

	void set_bool_opt(int level, int optname, bool optval);
}; /* class sctp_socket */
} /* namespace e2node */

#endif /* __e2node_sctp_socket__ */
