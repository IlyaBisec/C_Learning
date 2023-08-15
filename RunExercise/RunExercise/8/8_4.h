// Operation of overloaded arithmetic 
// operations with the 'Int' type

#pragma once

#include "..\stdafx.h"

class Int
{
public:

	Int() { m_Temp = 0; }
	Int(long double temp) : m_Temp(temp){}

	// Show result
	void displayInt() const { std::cout << m_Temp <<"\n"; }
	// Check overflow
	void checkOverflow(long double valueOverflow);
	
	// Arithmetic operations
	
	// Summation
	Int operator+(const Int &temp);

	// Subtraction
	Int operator-(const Int &temp);

	// Division
	Int operator/(const Int &temp);

	// Increase
	Int operator*(const Int &temp);

private:

	long double m_Temp;
};