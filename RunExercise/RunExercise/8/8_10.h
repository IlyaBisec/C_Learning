// The opertation of converting
// objects of the 'Sterling' class 
// to the double type

#pragma once

#include "..\stdafx.h"

class Sterling
{
public:

	Sterling() :m_Pounds(0), mShilling(0),
		m_Pens(0){}
	Sterling(double funt)
	{
		// converting
		m_Pounds = static_cast<long>(funt);
		
		long deschast = funt - m_Pounds;
		
		mShilling = static_cast<int>(deschast * 20);
		m_Pens = static_cast<int>((funt - m_Pounds) * 240
			- mShilling * 12);
	}
	Sterling(long pounds, int shilling, int pens) :
		m_Pounds(pounds), mShilling(shilling), m_Pens(pens){}

	void getSterling();
	void putSterling() const;

	Sterling operator+(const Sterling &sterling) const;
	Sterling operator-(const Sterling &sterling) const;
	double operator/(const Sterling &quantityTimes) const; // Количество раз

	Sterling operator*(double amount) const;
	Sterling operator/(double amount) const;

	operator double();

private:
	long m_Pounds;
	int mShilling, m_Pens;
};