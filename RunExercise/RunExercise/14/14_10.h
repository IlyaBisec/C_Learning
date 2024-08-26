// Exclusion generate for system of measuares
#ifndef _ENGLERR_EXCLUSION_GENERATE_H_
#define _ENGLERR_EXCLUSION_GENERATE_H_
#endif // !_ENGLERR_EXCLUSION_GENERATE_H_
#pragma once

#include <iostream>

namespace Template_14_10 {

	int isFeet(std::string);

	class Distance
	{
	public:
		Distance(): m_feet(0), m_inches(0.0){}
		Distance(int feet, float inches)
		{
			if (feet < -999 || feet > 999)
			{
				throw Exclusion(7);
			}
			m_feet = feet;
			if (inches >= 12.0 || inches < 0.0)
			{
				throw Exclusion(8);
			}
			m_inches = inches;
		}

		void get();
		void show() const
		{
			std::cout << m_feet << " - " << m_inches << '\"';
		}

		class Exclusion
		{
		public:
			Exclusion(int numb): errorNumber(numb){}
			int errorNumber;
		};
	private:
		int   m_feet;
		float m_inches;
	};

}