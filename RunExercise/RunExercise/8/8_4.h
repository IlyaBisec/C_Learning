#pragma once

#include "..\stdafx.h"

class Int
{
public:

	Int() { m_Temp = 0; }
	Int(long double temp) : m_Temp(temp){}

	// show result
	void displayInt() { std::cout << m_Temp <<"\n"; }
	//check overflow
	void checkOverflow(long double valueOverflow);
	
	// arithmetic operations
	
	// summation
	Int operator + (Int temp);

	// subtraction
	Int operator - (Int temp);

	// division
	Int operator / (Int temp);

	// increase
	Int operator * (Int temp);

private:

	long double m_Temp;
};