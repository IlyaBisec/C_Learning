// Overloaded operation '-' finds
// the distance difference

#pragma once

#include "..\stdafx.h"

class Distance
{
public:

	Distance(): mFeet(0), mInches(0.0){}
	Distance(int ft, float inch) : mFeet(ft), mInches(inch) {}

	void getDistance();
	void showDistance() const;
	
	Distance operator+ (const Distance &distance) const;
	Distance operator- (const Distance &distance) const;

private:

	int mFeet;
	float mInches;

};