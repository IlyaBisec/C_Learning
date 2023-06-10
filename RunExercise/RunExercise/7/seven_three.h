#pragma once
#include "stdafx.h"

class Distance
{
private:

	int feet;
	float inches;

public:

	Distance() {feet = 0; inches = 0;}
	Distance(int ft, float inch) : feet(ft), inches(inch) {}

	void getDistance();
	void showDistance() const;
	void addDistance(Distance, Distance);
	void divideDistance(Distance, int);
};