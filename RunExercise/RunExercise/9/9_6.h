// Demonstration of creating a secure array that checks
// its indexes when using
// (overloading the indexing operation [] is used)

#pragma once

#include "..\stdafx.h"

const int SIZE = 100;

// A class that implements a "safe array"
class SafeArray
{
public:
	
	int& operator[](int index);

	private:
		int m_Array[SIZE];
};

// Derived from the original safearray class, implementing
// the ability to define array boundaries
class BoundaryDeterminant : public SafeArray
{
public:

	BoundaryDeterminant(int lowerBoundary, int upperBoundary) :
		m_lowBoundary(lowerBoundary), m_upBoundary(upperBoundary)
	{
		if (m_lowBoundary > m_upBoundary)
			std::cout << "The upper bound of the array index cannot be less than the lower one\n";
		if (m_upBoundary - m_lowBoundary >= SIZE)
			std::cout << "Array overflow\n";
	}

	int& operator[](int index);

private:

	int m_lowBoundary, // Lower bound of the array index
		m_upBoundary; // Upper bound of the array index
	
};