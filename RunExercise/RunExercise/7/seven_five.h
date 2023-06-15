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
public:
	// Get values from user, get size of array
	// and writing to the array
	void getData(double values[], int size = 10);
	// Using previously recorded data to find the 
	// average value
	void averageValue(double values[], int size = 10);
};