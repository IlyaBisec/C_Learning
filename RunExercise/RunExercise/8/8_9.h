// Conversion of polar coordinates 
// to cartesian coordinates

#pragma once

#include "..\stdafx.h"

//class Casterian;
//class Polar;

namespace EightNine {

	// Интересный способ получить пи
	static const double PI = acos(-1.0);

	class Polar {
	public:

		Polar() : m_angle(0), m_radius(0) {}
		
		void getData(bool radians);
		void putData(bool radians) const;

		Polar operator+(const Polar &polar) const;
	private:

		double m_angle;
		double m_radius;

		
	};

}