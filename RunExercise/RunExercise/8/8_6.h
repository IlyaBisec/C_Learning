// Overloaded operation '-' substractions
// two 'time'

#include "..\stdafx.h"

#pragma once


class NewTime
{
public:

	NewTime() : m_Hours(0), m_Minutes(0), m_Seconds(0) {}
	NewTime(unsigned int hours, unsigned int minutes, unsigned int seconds) :
		m_Hours(hours), m_Minutes(minutes), m_Seconds(seconds) {}

	void displayTime() const
	{
		std::cout << m_Hours << ":" << m_Minutes << ":" << m_Seconds << "\n";
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

private:

	unsigned int m_Hours, m_Minutes, m_Seconds;
};