// Overloaded operations '++' and '--'
// for postfix and prefix forms

#include "..\stdafx.h"

#pragma once

class Time
{
public:

	Time() : m_hours(0), m_minutes(0), m_seconds(0) {}
	Time(long seconds) { convertSecondsToTime(seconds); }
	Time(int hours, int minutes, int seconds) :
		m_hours(hours), m_minutes(minutes), m_seconds(seconds) {}

	long convertTimeToSeconds()const;
	void convertSecondsToTime(long inputSeconds);

	void displayTime() const
	{
		std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << "\n";
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

	int m_hours, m_minutes, m_seconds;

};