#pragma once

#include "..\stdafx.h"

class Int
{
private:

	long double mTemp;

public:

	Int() { mTemp = 0; }
	Int(long double temp) : mTemp(temp){}

	// show result
	void displayInt() { std::cout << mTemp<<"\n"; }
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
};