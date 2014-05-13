#include <iostream>
#include "defines.h"
#include "simulation.h"
#include "helperConstructs.h"

using namespace std;

int main(){
	//Instantiate the simulation object
	Simulation sim;
	//Initialize variables to the state we desire
	Simulation::Initialize(sim);
	//main loop execution
	Simulation::RunSim(sim);
	
	return 0;
}