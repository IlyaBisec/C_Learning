#pragma once
// Overloads the multiplication operator so that two distances can be multiplied, 
// also making this friend function so that this expression Wdist = 7.5*dist2 is characteristic

#include "../stdafx.h"

namespace chapter_11 {

	class Distance
	{
	public:
		Distance(): m_feet(0),m_inches(0.0){}
		// Converting float to distance
		Distance(float floatNumber)
		{
			m_feet = static_cast<int>(floatNumber);
			m_inches = 12 * (floatNumber - m_feet);
		}
		Distance(int ft, float inch):m_feet(ft),m_inches(inch){}

		void showDist() const { std::cout << m_feet << "-" << m_inches; }
		
		friend float operator*(const Distance &, const Distance &); // Prototype

	private:
		int m_feet;
		float m_inches;
	};

	float operator*(const Distance &dis1, const Distance &dis2)
	{
		return (dis1.m_feet + dis1.m_inches / 12) * (dis2.m_feet + dis2.m_inches / 12);
	}
}