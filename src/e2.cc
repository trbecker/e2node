#include <e2node/e2.h>

namespace e2node {
e2::e2(sctp_socket *socket) : socket(socket)
{ /* Nothing */ }

e2::~e2()
{ /* Nothing */ }

void e2::connect(sock_info &info)
{
	this->socket->connect(info);
}

} /* namespace e2node */
