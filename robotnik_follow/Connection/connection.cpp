//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

extern "C" {
#include <remoteApi/extApi.h>
}

#include <iostream>
#include <thread>
#include <include/v_repConst.h>
#include "connection.h"

Connection::Connection():server_ip("127.0.0.1"), server_port(19997), time_out_in_ms(1000), comm_thread_cycle_in_ms(5),
                         waitUntilConnected(true), doNotReconnectOnceDisconnected(true), client_id(-1), robot_handle(-1)
{
	std::cout << "Trying to connect\n";
	while (!isConnected())
	{
		std::cout << "Trying to connect\n";
		client_id = simxStart((simxChar *) server_ip.c_str(), (simxInt) server_port, (simxUChar) waitUntilConnected,
		                      (simxUChar) doNotReconnectOnceDisconnected, time_out_in_ms, comm_thread_cycle_in_ms);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	std::cout << "Connection successful\n";
//	simxStartSimulation(client_id, simx_opmode_oneshot);

}

bool Connection::isConnected() const
{
	return simxGetConnectionId(client_id) != -1;
}

int Connection::getClientId() const
{
	return client_id;
}

Connection::~Connection()
{
	stopSimulation();
	simxFinish(client_id); // fechando conexao com o servidor
	std::cout << "Conexion closed!\n";
}

int Connection::getRobotHandle() const
{
	return robot_handle;
}

void Connection::setRobotHandle(int robot_handle)
{
	Connection::robot_handle = robot_handle;
}


void Connection::stopSimulation()
{
	simxStopSimulation(client_id, simx_opmode_oneshot);
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
}


