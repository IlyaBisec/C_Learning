// Overloaded operation '-' substractions
// two 'time'

#include "..\stdafx.h"

#pragma once


class NewTime
{
public:

	NewTime() : m_hours(0), m_minutes(0), m_seconds(0) {}
	NewTime(unsigned int hours, unsigned int minutes, unsigned int seconds) :
		m_hours(hours), m_minutes(minutes), m_seconds(seconds) {}

	void displayTime() const
	{
		std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << "\n";
	}

	// arithmetic operations
	NewTime operator+(const NewTime &time) const;
	NewTime operator-(const NewTime &time) const;
	NewTime operator*(const NewTime &time) const;

	// unary operations

	// postfix
	NewTime operator++(int);
	NewTime operator--(int);

	// prefix
	NewTime &operator++();
	NewTime &operator--();

private:

	unsigned int m_hours, m_minutes, m_seconds;
};