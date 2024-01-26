#pragma once

#include "../stdafx.h"

namespace chapter_11 {

	class Distance
	{
	public:
		Distance(): m_feet(0),m_inches(0.0){}
		Distance(float temp_feet)
		{
			m_feet = static_cast<int>(temp_feet);
			temp_feet, m_inches = 12 * (temp_feet - m_feet);
		}
		Distance(int ft, float inch):m_feet(ft),m_inches(inch){}

		void showDist() const { std::cout << m_feet << "-" << m_inches; }
		
		friend float operator*(Distance, Distance); // Prototype

	private:
		int m_feet;
		float m_inches;
	};

	float operator*(Distance dis1, Distance dis2)
	{
		return (dis1.m_feet + dis1.m_inches / 12) * (dis2.m_feet + dis2.m_inches / 12);
	}
}