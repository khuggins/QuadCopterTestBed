#include "rungeKutta.h"
#include "uavProperties.h"
// So this should totally be a runge-kutta in the future
// Right now I don't have the patience to set it up that way.
// So its the simplest method, Euler.
xyz integrate(xyz derivative, xyz state, float dt){
	state.x = state.x + derivative.x*dt;
	state.y = state.y + derivative.y*dt;
	state.z = state.z + derivative.z*dt;

	return state;
}

void IntegrateRoutine(Simulation& sim){
	float time = sim.getTime();

	sim.UAV.setVelocity(integrate(sim.UAV.getAcceleration(), sim.UAV.getVelocity(), sim.gettStep()));
	sim.UAV.setPosition(integrate(sim.UAV.getVelocity(), sim.UAV.getPosition(), sim.gettStep()));
	sim.setTime(time += sim.gettStep());
	return;
}


