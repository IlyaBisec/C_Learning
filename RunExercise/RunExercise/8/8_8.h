// Checking the overflow of the
// array from above and below

#include "../stdafx.h"
#pragma once

const int LIMIT = 100;

class NewSafeArray
{
public:

	NewSafeArray(int lower, int upper):m_lowerBound(lower), m_upperBound(upper)
	{
		if (m_lowerBound > m_upperBound)
		{
			std::cout << "Upper bound of the array index cannot be less than the lower bound\n";
			exit(1);
		}
		if (m_upperBound - m_lowerBound >= LIMIT)
		{
			std::cout << "Array overflow\n";
			exit(1);
		}
	}

	// Function return reference
	int& operator [](int index);
	const int &operator [](int index) const;

private:
	int m_array[LIMIT];
	int m_lowerBound,
	    m_upperBound;

};