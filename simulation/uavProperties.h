#include "helperConstructs.h"
#include <vector>

//only define class once
#ifndef UAVPROPERTIES_H
#define UAVPROPERTIES_H
class Uav{
private:
	xyz position;			//meters
	xyz velocity;			//meters/second
	xyz acceleration;		//meters/second^2
	xyz orientation;		//radians
	std::vector<xyz> arm;	//meters (relative to uav fixed coordinate system)
	float mass;				//kilograms
	status state;			//enumerated type. 
public:
	//default constructor
	Uav();
	
	//Accessors
	float getMass(){ return mass; };
	xyz getPosition(){ return position; };
	xyz getOrientation(){ return orientation; };
	xyz getAcceleration(){ return acceleration; };
	xyz getVelocity(){ return velocity; };
	status getState(){ return state; };

	void setMass(float mass_){ mass=mass_; };
	void setPosition(xyz pos_){ position=pos_; };
	void setOrientation(xyz orient_){ orientation=orient_; };
	void setAcceleration(xyz acc_){ acceleration=acc_; };
	void setVelocity(xyz vel_){ velocity = vel_; };
	void setState(status state_){ state=state_; };
};
#endif


