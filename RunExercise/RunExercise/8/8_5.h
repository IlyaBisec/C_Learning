// Overloaded operations '++' and '--'
// for postfix and prefix forms

#include "..\stdafx.h"

#pragma once

/*тут надо улучшить 2 момента:
1. Префиксный инкремент/декреремент должны возврщать ссылку на себя же. Т.е. должен быть return *this;
Иначе, например, вот такой код не будет правильно работать: ++(++a);
2. Постфиксные инкремент и декремент сейчас технически реализованы верно.
Но лучше их делать через вызов префиксных. тобы не было дублирования логики.
т.е. обычно делают так:
Time tmp;
++(*this);
return tmp;*/


class Time
{
public:

	Time() : mHours(0), mMinutes(0), mSeconds(0) {}
	Time(unsigned int hours, unsigned int minutes, unsigned int seconds) :
		mHours(hours), mMinutes(minutes), mSeconds(seconds) {}

	void displayTime() const
	{
		std::cout << mHours << ":" << mMinutes << ":" << mSeconds << "\n";
	}

	//Time operator + (Time time);

	// unary operations
	
	// postfix
	Time operator++(int);
	Time operator--(int);

	// prefix
	Time operator++();
	Time operator--();

private:

	unsigned int mHours, mMinutes, mSeconds;

};