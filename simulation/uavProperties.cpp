#include "uavProperties.h"
#include "helperConstructs.h"

Uav::Uav(){
	// position of center x y z in fixed inertial space (world)
	xyz pos(0, 0, 0);
	//roll pitch yaw
	xyz orient(0, 0, 0);
	xyz velocity(0, 0, 0);
	xyz acceleration(0, 0, 0);

	std::vector<xyz> arm;
	//arms are added ccw
	arm.push_back(xyz(0.2, 0.0, 0.0));
	arm.push_back(xyz(0.0, 0.2, 0.0));
	arm.push_back(xyz(-0.2, 0.0, 0.0));
	arm.push_back(xyz(0.0, -0.2, 0.0));
}