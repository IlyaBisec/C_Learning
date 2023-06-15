// Finding the average value
// received from the user

#pragma once

#include "..\stdafx.h"

// class FractionPart using for find the average value.
// It contains:
//		
//		getData();
//		averageValue();				
//
// double values[SIZE]
//
// Get values from user, get size of array
// FractionPart::getData(values, SIZE);
//
// Find the average value
// FractionPart::averageValue(values, SIZE);
class FractionPart
{
private:

	static const int SIZE = 10;
	double m_values[SIZE];

public:

	// Get values from user, get size of array
	// and writing to the array
	void getData();
	// Using previously recorded data to find the 
	// average value
	void averageValue();
};