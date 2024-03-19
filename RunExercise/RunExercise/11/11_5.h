#pragma once
// A program from example of book, supplemented with overloaded friendly functions
// long double * bMoney  -  Multiply a number by money
// long double / bMoney - Dividing a number by money

#include "../stdafx.h"


namespace chapter11_5 
{
	// A class representing a monetary amount in dollars and cents
	class bMoney {
	
	public:
		bMoney()
		{
			m_sum = 0.0L;
		}
		// long double to bMoney
		explicit bMoney(long double n) : m_sum(n) {}
		bMoney(const char s[]) // The money line
		{
			mstold(s);
		}
		
		// The method converts a money string into a long double number
		long double mstold(const char[]);
		
		// Converts a long double (m_sum) number to a money string and returns this string via the first parameter
		void ldtoms(char[]);
		
		void getmoney();
		void putmoney();

		
		bMoney operator+(const bMoney &money) const { return bMoney(m_sum + money.m_sum);}
		bMoney operator-(const bMoney &money) const { return bMoney(m_sum - money.m_sum); }
	
		bMoney operator*(long double n) const { return bMoney(m_sum * n); }
		bMoney operator/(long double n) const { return bMoney(m_sum / n); }

		long double operator/(const bMoney &money) const { return m_sum / money.m_sum; }
		
		// long double * bMoney
		friend bMoney operator*(long double, const bMoney &money);
		// long double / bMoney
		friend long double operator/(long double, const bMoney &money);

	private:
		long double m_sum; // The amount of money in dollars and cents
	};

	// A class-friendly bMoney operator for processing expressions of the form long double * bMoney
	bMoney operator* (long double n, const bMoney &m) { return bMoney(n * m.m_sum); }

	// A class-friendly bMoney operator for processing expressions of the form long double / bMoney
	long double operator/ (long double n, const bMoney &m) { return (n / m.m_sum); }

}

