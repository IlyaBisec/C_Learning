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

	Time() : m_Hours(0), m_Minutes(0), m_Seconds(0) {}
	Time(long seconds) { convertSecondsToTime(seconds); }
	Time(int hours, int minutes, int seconds) :
		m_Hours(hours), m_Minutes(minutes), m_Seconds(seconds) {}

	long convertTimeToSeconds()const;
	void convertSecondsToTime(long inputSeconds);

	void displayTime() const
	{
		std::cout << m_Hours << ":" << m_Minutes << ":" << m_Seconds << "\n";
	}
	void addTime(const Time &time1, const Time &time2);

	//Time operator + (Time time);

	// Unary operations
	Time operator+(const Time &time) const;

	// Postfix
	Time operator++(int);
	Time operator--(int);

	// Prefix
	Time &operator++();
	Time &operator--();

private:

	int m_Hours, m_Minutes, m_Seconds;

};