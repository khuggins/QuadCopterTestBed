#include "helperConstructs.h"
#include "uavProperties.h"
#include "simulation.h"
xyz integrate(xyz derivative, xyz state, float tStep);
void IntegrateRoutine(Simulation& sim);
status EndLoopCheck(Uav& UAV);