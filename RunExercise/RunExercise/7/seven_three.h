// Calculates the average value
// of the lengths entered by the user

#pragma once
#include "..\stdafx.h"

class Distance
{
public:

	Distance() { mFeet = 0; mInches = 0;}
	Distance(int ft, float inch) : mFeet(ft), mInches(inch) {}

	void getDistance();
	void showDistance() const;
	void addDistance(const Distance&, const Distance&);
	void divideDistance(const Distance&, int);

private:

	int mFeet;
	float mInches;

};