//
// Laboratory of Robotics and Cognitive Science
// Created by:  Leonardo de Oliveira Ramos
// Github:      https://github.com/oramleo
//

extern "C"
{
#include "extApi.h"
#include "v_repConst.h"
#include "extApiPlatform.h"
}

#include <iostream>
#include "../Monitor/monitor_sonar_vrep.h"
#include "../Analyze/analyze_pioneer_p_3_dx.h"
#include "../Knowledge/pioneer_p3dx_model.h"
#include "planner_pioneer_p3dx.h"

PlannerPioneerP3DX::PlannerPioneerP3DX(RobotModel &robot_, std::vector<AnalyzePioneerP3DX> &analyzes_)
	: robot(robot_), analyzes(analyzes_), no_detection_dist(0.5),
		max_detection_dist(0.2), detect{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		braitenberg_l{-0.2, -0.4, -0.6, -0.8, -1, -1.2, -1.4, -1.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
		braitenberg_r{-1.6, -1.4, -1.2, -1, -0.8, -0.6, -0.4, -0.2, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
		v0(2), v_left(0), v_right(0)
{
}

void PlannerPioneerP3DX::runPlanner()
{
	//	Temporary
	// inicialização dos motores
	int leftMotorHandle = 0;
	int rightMotorHandle = 0;
	if (simxGetObjectHandle(((PioneerP3DXModel&)robot).getConnection().getClientId(), (const simxChar *) "Pioneer_p3dx_leftMotor", (simxInt *) &leftMotorHandle,
													(simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
		std::cout << "Handle do motor esquerdo nao encontrado!" << std::endl;
	else
		std::cout << "Conectado ao motor esquerdo!" << std::endl;

	if (simxGetObjectHandle(((PioneerP3DXModel&)robot).getConnection().getClientId(), (const simxChar *) "Pioneer_p3dx_rightMotor", (simxInt *) &rightMotorHandle,
													(simxInt) simx_opmode_oneshot_wait) != simx_return_ok)
		std::cout << "Handle do motor direito nao encontrado!" << std::endl;
	else
		std::cout << "Conectado ao motor direito!" << std::endl;


	while (((PioneerP3DXModel&)robot).getConnection().isConnected()) // enquanto a simulação estiver ativa
	{
		for (int i = 0; i < 16; i++)
		{
			char state;

			Position coord{0,0,0};
//			float coord[3];
			AnalyzePioneerP3DX an = (AnalyzePioneerP3DX)analyzes[0];
			std::vector<MonitorSonarVrep> monits = an.getMonitors();
//			std::cout << monits[i].getSonar().getSonarHandle() << std::endl;

//			int id = connection.getClientId();
//			if (simxReadProximitySensor(id, monits[i].getSonar().getSonarHandle(), (simxUChar*) &state, coord, NULL, NULL,
//																	simx_opmode_buffer) == simx_return_ok)
			if (((AnalyzePioneerP3DX&)analyzes[0]).getSonarData(i, coord, state))
			{
//				double dist = coord.getZ();
				double dist = coord.getZ();
				if (state > 0 && (dist < no_detection_dist))
				{
					if (dist < max_detection_dist)
					{
						dist = max_detection_dist;
					}

					detect[i] = 1 - ((dist - max_detection_dist) / (no_detection_dist - max_detection_dist));
				}
				else
					detect[i] = 0;
			}
			else
				detect[i] = 0;
//			std::cout << detect[i];
		}
//		std::cout << std::endl;

		v_left = v0;
		v_right = v0;

		for (int i = 0; i < 16; i++)
		{
			v_left = v_left + braitenberg_l[i] * detect[i];
			v_right = v_right + braitenberg_r[i] * detect[i];
		}

		// atualiza velocidades dos motores
		simxSetJointTargetVelocity(((PioneerP3DXModel&)robot).getConnection().getClientId(), leftMotorHandle, (simxFloat) v_left, simx_opmode_streaming);
		simxSetJointTargetVelocity(((PioneerP3DXModel&)robot).getConnection().getClientId(), rightMotorHandle, (simxFloat) v_right, simx_opmode_streaming);

		// espera um pouco antes de reiniciar a leitura dos sensores
		extApi_sleepMs(50);
	}
}