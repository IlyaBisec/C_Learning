#pragma once
#ifndef _VERYLONG_H_
#define _VERYLONG_H_
#endif // !_VERYLONG_H_

// Verylong - class of very long numbers
#include <iostream>
#include <string.h>
#include <stdlib.h>

const int SIZE = 1000; // Max number of digits


class Verylong
{
public:
	Verylong() : m_vl_len(0) { m_vl_string[0] = '\0'; }
	Verylong(const char s[SIZE]) 
	{  
		std::strcpy(m_vl_string, s); 
		m_vl_len = std::strlen(s);
	}
	Verylong(const unsigned long n)
	{
		itoa(n, m_vl_string, 10);	// Convert to string
		strrev(m_vl_string);		// Flip her
		m_vl_len = strlen(m_vl_string); // Find length
	}

	void put() const;
	void get();

	Verylong operator+(const Verylong &largeNumber);
	Verylong operator-(const Verylong &largeNumber);
	Verylong operator*(const Verylong &largeNumber);
	Verylong operator/(const Verylong &largeNumber);
	Verylong operator%(const Verylong &largeNumber);

private:
	char m_vl_string[SIZE];	// Number as a string
	int m_vl_len;			// Length of Verylong string

	Verylong multDigit(const int) const;
	Verylong mult_10(const Verylong &largeNumber) const;
};