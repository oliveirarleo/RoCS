//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

#ifndef PIONEER_CONNECTION_H_
#define PIONEER_CONNECTION_H_


#include <string>

extern "C" {
#include <remoteApi/extApi.h>
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

	int robot_handle;


public:
	Connection();

	virtual ~Connection();

	bool isConnected() const;

	int getClientId() const;

	int getRobotHandle() const;

	void setRobotHandle(int robot_handle);

	void stopSimulation();

};

#endif // PIONEER_CONNECTION_H_
