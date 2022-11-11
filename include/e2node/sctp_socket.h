#ifndef __e2node_sctp_socket__
#define __e2node_sctp_socket__
#include <string>

namespace e2node {

class sock_info {
public:
	sock_info(const std::string &addr, const int port) :
		addr(addr), port(port) { /* Nothing */ }
	sock_info(const sock_info &other) :
		addr(other.addr), port(other.port) { /* Nothing */ }

	const std::string addr;
	const int port;
}; /* class sock_info */

class sctp_socket {
public:
	static const std::string addr_any;

	sctp_socket();
	virtual ~sctp_socket();
	virtual void connect(const sock_info &peer);
	virtual void bind(const sock_info &peer);
	virtual int send(const void *buffer, size_t len, int flags=0);
	virtual int recv(void *buffer, size_t len, int flags=0);
	void set_reuse_port(bool reuse);
	void set_reuse_address(bool reuse);

protected:
	virtual void set_bool_opt(int level, int optname, bool optval);

private:
	int _socket;
	bool up;

	void create();

}; /* class sctp_socket */
} /* namespace e2node */

#endif /* __e2node_sctp_socket__ */
