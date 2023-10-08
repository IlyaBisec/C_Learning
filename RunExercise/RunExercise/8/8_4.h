// Operation of overloaded arithmetic 
// operations with the 'Int' type

#pragma once

#include "..\stdafx.h"

class Int
{
public:

	Int() { m_temp = 0; }
	Int(long double temp) : m_temp(temp){}

	// Show result
	void displayInt() const { std::cout << m_temp <<"\n"; }
	// Check overflow
	void checkOverflow(long double valueOverflow) const;
	
	// Arithmetic operations
	
	// Summation
	Int operator+(const Int &temp) const;

	// Subtraction
	Int operator-(const Int &temp) const;

	// Division
	Int operator/(const Int &temp) const;

	// Increase
	Int operator*(const Int &temp) const;

private:

	long double m_temp;
};