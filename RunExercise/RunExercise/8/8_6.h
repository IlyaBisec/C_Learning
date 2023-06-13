#include "..\stdafx.h"

#pragma once


class NewTime
{
private:

	unsigned int mHours, mMinutes, mSeconds;

public:

	NewTime() : mHours(0), mMinutes(0), mSeconds(0) {}
	NewTime(unsigned int hours, unsigned int minutes, unsigned int seconds) :
		mHours(hours), mMinutes(minutes), mSeconds(seconds) {}

	void displayTime() const
	{
		std::cout << mHours << ":" << mMinutes << ":" << mSeconds << "\n";
	}

	// arithmetic operations
	NewTime operator + (NewTime time);
	NewTime operator - (NewTime time);
	NewTime operator * (NewTime time);

	// unary operations

	// postfix
	NewTime operator++(int);
	NewTime operator--(int);

	// prefix
	NewTime operator++();
	NewTime operator--();

};