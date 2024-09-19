// A very large number & arithmetic operation with it

#pragma once
#ifndef _VERYLONG_H_
#define _VERYLONG_H_
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int SIZE = 1000; // Max number of digits
typedef unsigned long UL;


class Verylong
{
public:
	Verylong() : m_length(0), m_sign(true)
	{
		m_string[0] = L'\0';
	}
	Verylong(const wchar_t s[SIZE])   
	{
		wcscpy(m_string, s); m_length = wcslen(s); m_sign = true;
	}
	Verylong(const long number)         
	{
		// Define the sign of the number
		if (number < 0)
			m_sign = false;
		else
			m_sign = true;

		// Convert to string
		_ltow(abs(number), m_string, 10);  
		// Flip number in row (the higher digits will become the 
		// lower ones and vice versa)
		_wcsrev(m_string);              
		// Find lingth of number in the string							 
		m_length = wcslen(m_string);    
	}
	void put() const;              
	void get();          

	Verylong operator+ (const Verylong); 
	Verylong operator- (const Verylong); 
	Verylong operator* (const Verylong); 
	Verylong operator/ (const Verylong); 
	Verylong operator% (const Verylong); 

private:
	// Array (string) for storing a very long integer
	wchar_t m_string[SIZE]; 
	int m_length;         
	// Sign of number,  true '+', false '-'
	bool m_sign;        

	Verylong addBy(const Verylong) const;  
	Verylong subtract(const Verylong) const;
	Verylong multiply(const Verylong) const;
	Verylong devide(const Verylong, bool) const;

	int compare(const Verylong) const;
	
	Verylong multdigit(const int) const;                
	Verylong mult10(const Verylong) const;  
};


#endif // !_VERYLONG_H_