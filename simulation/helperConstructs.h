#ifndef HELPERCONSTRUCTS_H
#define HELPERCONSTRUCTS_H
struct xyz{
	float x;
	float y;
	float z;
	xyz() :
		x(0),
		y(0),
		z(0){}
	xyz(float x_, float y_, float z_):
		x (x_),
		y (y_),
		z (z_){}
};

struct iteration{
	float printSummary;
	float printTelem;
	iteration() :
		printSummary(0.0),
		printTelem(0.0){}
};
enum status{
	NORMAL,
	MIN_ALTITUDE,
	MAX_TIME
};
#endif