#include "uavProperties.h"

#ifndef SIMULATION_H
#define SIMULATION_H
class Simulation{
private:
	float time,tStep,endTime;//master time for all of simulation
public:
	Uav UAV;
	//default constructor
	Simulation();

	//public member functions
	static void Initialize(Simulation& sim);
	static void RunSim(Simulation& sim);
	static status EndLoopCheck(Uav& UAV);
	static void printSummary(Simulation sim);
	static void printSummary();
	//Accessors
	void setTime(float time_){ time = time_; }
	float getTime(){ return time; }
	float gettStep(){ return tStep; }

};
#endif