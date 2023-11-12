// The opertation of converting
// objects of the 'Sterling' class  to the double type

#pragma once

#include "..\stdafx.h"

class Sterling
{
public:

	Sterling() :m_pounds(0), m_shilling(0),
		m_pens(0){}
	Sterling(double funt)
	{
		// Converting
		m_pounds = static_cast<long>(funt);
		
		long deschast = funt - m_pounds;
		
		m_shilling = static_cast<int>(deschast * 20);
		m_pens = static_cast<int>((funt - m_pounds) * 240
			- m_shilling * 12);
	}
	Sterling(long pounds, int shilling, int pens) :
		m_pounds(pounds), m_shilling(shilling), m_pens(pens){}

	void getSterling();
	void putSterling() const;

	Sterling operator+(const Sterling &sterling) const;
	Sterling operator-(const Sterling &sterling) const;
	double operator/(const Sterling &quantityTimes) const; // Количество раз

	Sterling operator*(double amount) const;
	Sterling operator/(double amount) const;

	operator double();

private:
	long m_pounds;
	int m_shilling, m_pens;
};