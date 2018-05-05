//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef ROCS_CONNECTION_H_
#define ROCS_CONNECTION_H_

#include <string>

extern "C" {
#include "../../lib/remoteApi/extApi.h"
}

class Connection
{
private:
	std::string server_ip;
	int server_port;

	simxInt time_out_in_ms;
	simxInt comm_thread_cycle_in_ms;

	bool waitUntilConnected;
	bool doNotReconnectOnceDisconnected;

	int client_id;

public:
	Connection();

	Connection(const std::string &server_ip, int server_port, simxInt time_out_in_ms, simxInt comm_thread_cycle_in_ms,
						 bool waitUntilConnected, bool doNotReconnectOnceDisconnected, int client_id);

	virtual ~Connection();

	bool isConnected();

	int getClientId() const;
};


#endif // ROCS_CONNECTION_H_
