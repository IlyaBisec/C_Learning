// A very large number & arithmetic operation with it

#pragma once
#ifndef _VERYLONG_H_
#define _VERYLONG_H_
#endif // !_VERYLONG_H_

#include <iostream>
#include <string.h>
#include <stdlib.h>

const int SIZE = 1000; // Max number of digits
typedef unsigned long UL;

// Verylong - class of very long numbers
class Verylong
{
public:
	Verylong() : m_length(0), m_sign(true) { m_string[0] = '\0'; }
	Verylong(const char s[SIZE]) 
	{  
		strcpy_s(m_string, s); 
		m_length = std::strlen(s);
		m_sign = true;
	}
	Verylong(const long n)
	{
		// Check sign
		if(n < 0){
			m_sign = false;
		}
		else {
			m_sign = true;
		}

		_itoa_s(n, m_string, 10);	// Convert to string
		_strrev(m_string);		// Flip her
		m_length = strlen(m_string); // Find length
	}

	void put() const;
	void get();

	// Arithmetic operations of +, -, *, / and % , very long integers
	Verylong operator+(const Verylong &largeNumber);
	Verylong operator-(const Verylong &largeNumber);
	Verylong operator*(const Verylong &largeNumber);
	Verylong operator/(const Verylong &largeNumber);
	Verylong operator%(const Verylong &largeNumber);

private:
	char m_string[SIZE];	// Number as a string
	int m_length;			// Length of Verylong string
	bool m_sign;			// Sign of number, true = '+', false = '-'

	// The sum of two positive very long integers
	Verylong addBy(const Verylong &largeNumber) const;
	// The substraction of two positive very long integers
	Verylong subtract(const Verylong &largeNumber) const;
	// The multiplication of two positive very long integers
	Verylong multiply(const Verylong &largeNumber) const;
	// The division of two positive very long integers
	// Flag: 
	// true - result, 
	// false - tre remaining of division
	Verylong divide(const Verylong &largeNumber, bool flag) const;
	// Multiplying the current number by a digit argument
	Verylong multiDigit(const int) const;
	// Multiplying the argument by 10
	Verylong multi_10(const Verylong &largeNumber) const;

	// Comparison of modules of numbers, excluding signs
	// if the current number is greater than the argument, then 1 is returned, if less than 0,
	// if equal, 2 is returned
	int compare(const Verylong &largeNumber) const;
};