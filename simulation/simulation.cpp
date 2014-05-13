#include <vector>
#include "simulation.h"
#include "defines.h"
#include "rungeKutta.h"
#include <iostream>

using namespace std;

//Default constrcutor
Simulation::Simulation(){
	time = 0;
	tStep = TIME_STEP;
	endTime = 10;
}

//Post construtor, let's set up some conditions based on
//what we want for this specific simulation run
void Simulation::Initialize(Simulation& sim){
	sim.UAV.setPosition(xyz(0, 0, 10));
	sim.UAV.setAcceleration(xyz(0, 0, GRAV));

}

void Simulation::RunSim(Simulation& sim){
	printSummary();
	iteration counter;
	while (sim.UAV.getState() == NORMAL){

		//After all the guidance loop has reacted to the current timestep
		//and the acceleration commands, motor commands, are all processed,
		//we advance the timestep and integrate up everything
		IntegrateRoutine(sim);
		//Check for flight conditions at end of loop. If we've
		//crashed (min alt) then break out of the while loop.
		//Otherwise, keep on cruisin.
		EndLoopCheck(sim.UAV);
		if (counter.printSummary > SUMMARY_TIME_STEP){
			printSummary(sim);
			counter.printSummary = 0;
		}

		//increment timers that keep track of various things.
		//mostly to adjust the rate of output of telemetry and summary
		counter.printSummary += TIME_STEP;
		counter.printTelem += TIME_STEP;
	}
}


//checks end of sim conditions
status Simulation::EndLoopCheck(Uav& UAV){
	if (UAV.getPosition().z < 0){
		UAV.setState(MIN_ALTITUDE);
		return MIN_ALTITUDE;
	}
}

void Simulation::printSummary(){
	printf("%6s%6s\n","time","z-pos");
}
void Simulation::printSummary(Simulation sim){
	printf("%6.1f%6.1f\n", sim.getTime(),sim.UAV.getPosition().z);
}