#pragma once
// Calculator with template
#ifndef _CALCULATOR_TEMPLATE_H_
#define _CALCULATOR_TEMPLATE_H_

#include <iostream>

namespace Template_14_7
{
	template <class F>
	class Fraction
	{
	public:
		Fraction(){}
		Fraction(F num, F denum) : m_numirator(num),
			m_denumirator(denum){ }

		void get();
		void display() const;

		Fraction operator+ (const Fraction &fraction) const
		{
			return Fraction(m_numirator * fraction.m_denumirator + fraction.m_numirator * m_denumirator,
				m_denumirator * fraction.m_denumirator).lowterms();
		}
		Fraction operator- (const Fraction &fraction) const
		{
			return Fraction(m_numirator * fraction.m_denumirator - fraction.m_numirator * m_denumirator,
				m_denumirator * fraction.m_denumirator).lowterms();
		}
		Fraction operator* (const Fraction &fraction) const
		{
			return Fraction(m_numirator * fraction.m_numirator, 
				m_denumirator * fraction.m_denumirator).lowterms();
		}
		Fraction operator/ (const Fraction &fraction) const
		{
			return Fraction(m_numirator * fraction.m_denumirator,
				m_denumirator * fraction.m_numirator).lowterms();
		}

		bool operator== (const Fraction &fraction) const
		{
			if ((m_numirator == fraction.m_numirator) &&
				(m_denumirator == fraction.m_denumirator))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		bool operator!= (const Fraction &fraction) const
		{
			if ((m_numirator == fraction.m_numirator) &&
				(m_denumirator == fraction.m_denumirator))
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		Fraction lowterms();

	private:
		F m_numirator,
		  m_denumirator;
	};
}
#endif // !_CALCULATOR_TEMPLATE_H_