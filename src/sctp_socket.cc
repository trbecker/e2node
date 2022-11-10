#include <exception>
#include <cassert>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <arpa/inet.h> /* inet_addr() */

#include <e2node/sctp_socket.h>

namespace e2node {
class sctp_exception : public std::exception {
public:
	sctp_exception(const char *_what) : _what(_what) { }
	sctp_exception(int err) : _what(strerror(err)) { }

	const char *what() const noexcept override {
		return this->_what;
	}
private:
	const char *_what;
};

const std::string sctp_socket::addr_any("any");

sctp_socket::sctp_socket() : up(false)
{
	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP); 
	if (sock == -1)
		throw sctp_exception(errno); // GCOVR_EXCL_LINE

	this->_socket = sock;
}


sctp_socket::~sctp_socket() 
{
	if (this->_socket > 0)
		close(this->_socket);
}

void sctp_socket::connect(const sock_info &info)
{
	struct sockaddr_in peer;
	memset(&peer, 0, sizeof(struct sockaddr_in));
	peer.sin_family = AF_INET;
	peer.sin_port = htons(info.port);
	peer.sin_addr.s_addr = inet_addr(info.addr.c_str());

	if (::connect(this->_socket, (struct sockaddr *)&peer, sizeof(peer)) == -1)
		throw sctp_exception(errno);  // GCOVR_EXCL_LINE

	up = true; // GCOVR_EXCL_LINE needs a server or a mockup connect
}

void sctp_socket::bind(const sock_info &info)
{
	struct sockaddr_in addr;

	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(info.port);

	if (info.addr == addr_any)
		addr.sin_addr.s_addr = INADDR_ANY;
	else
		addr.sin_addr.s_addr = inet_addr(info.addr.c_str());

	if (::bind(this->_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1)
		throw sctp_exception(errno); // GCOVR_EXCL_LINE

	up = true; // GCOVR_EXCL_LINE needs a server or a mockup connect
}

int sctp_socket::send(const void *buffer, size_t len, int flags)
{
	if (!this->up)
		throw sctp_exception("socket not connected");
// GCOVR_EXCL_START needs server or mockup
	int bytes_sent = 0;
	if ((bytes_sent = ::send(this->_socket, buffer, len, flags)) == -1)
		throw sctp_exception(errno);
	return bytes_sent;
// GCOVR_EXCL_STOP
}

int sctp_socket::recv(void *buffer, size_t len, int flags)
{
	if (!this->up)
		throw sctp_exception("socket not connected");
// GCOVR_EXCL_START needs server or mockup
	int bytes_recv = 0;
	if ((bytes_recv = ::recv(this->_socket, buffer, len, flags)) == -1)
		throw sctp_exception(errno);
	return bytes_recv;
// GCOVR_EXCL_STOP
}

void sctp_socket::set_bool_opt(int level, int optname, bool optval) {
	auto _optval = (optval ? 1 : 0);
	if (setsockopt(this->_socket, level, optname,
			(const void *)&_optval, sizeof(_optval)) != 0)
		throw sctp_exception(errno); // GCOVR_EXCL_LINE
}

void sctp_socket::set_reuse_port(bool reuse)
{
	this->set_bool_opt(SOL_SOCKET, SO_REUSEPORT, reuse);
}

void sctp_socket::set_reuse_address(bool reuse)
{
	this->set_bool_opt(SOL_SOCKET, SO_REUSEADDR, reuse);
}

} /* namespace e2node */
