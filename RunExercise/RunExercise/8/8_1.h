#pragma once

#include "..\stdafx.h"

class Distance
{
private:

	int mFeet;
	float mInches;

public:

	Distance(): mFeet(0), mInches(0.0){}
	Distance(int ft, float inch) : mFeet(ft), mInches(inch) {}

	void getDistance();
	void showDistance() const;
	
	Distance operator+ (Distance distance) const;
	Distance operator- (Distance distance) const;
};