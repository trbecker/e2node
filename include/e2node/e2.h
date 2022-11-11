#ifndef __e2node_e2__
#define __e2node_e2__
#include <e2node/sctp_socket.h>

namespace e2node {
class e2 {
public:
	e2(sctp_socket *socket);
	virtual ~e2();

	void connect(sock_info &info);

private:
	sctp_socket *socket;
}; /* class e2 */

} /* namespace e2node */
#endif /* __e2node_e2__ */
