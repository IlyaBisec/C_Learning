//Convert money line to number

#pragma once

#include "..\stdafx.h"
class Money
{
public:

	Money():mNumber(0){}

	// convert money line to long double
	void mstold();
	// summation of two types of Money type
	void madd(Money money1, Money money2);
	// show results
	void display() const;

private:

	std::string mMoneyLine;
	long double mNumber;

};