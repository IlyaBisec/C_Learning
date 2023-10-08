#include "8_9.h"

int main8_9()
{
	EightNine::Polar polar1, polar2, result;

	std::cout << "Input 1 point in the polar coordinates: "; polar1.getData(false);
	std::cout << "Input 2 point in the polar coordinates: "; polar2.getData(false);

	result = polar1 + polar2;
	std::cout << "Result: "; result.putData(false);
	

	return 0;
}


namespace EightNine {


	void Polar::getData(bool radians)
	{
		std::cout << "Input radius: ";
		std::cin >> m_radius;

		if (m_radius < 0) {
			std::cout << "Radius < 0!\n";
			exit(1);
		}

		if (radians)
		{
			std::cout << "Input angle in the radians: ";
			std::cin >> m_angle;
		}
		else
		{
			std::cout << "Input angle in the degrees: ";
			int tempDeg;
			std::cin >> tempDeg;
			m_angle = tempDeg * PI / 180;
		}
	}

	void Polar::putData(bool radians) const
	{
		std::cout << "Radius: " << m_radius << "\n";

		if (radians)
			std::cout << "Angle in the radians: " << m_angle << "\n";
		else
			std::cout << "Angle in the degrees: " << m_angle * PI / 180 << "\n";


	}

	Polar Polar::operator+(const Polar &polar) const
	{
		// Convert polar coordinates of the first point into Cartesian
		double x = m_radius * cos(m_angle);
		double y = m_radius * sin(m_angle);

		// Convert the polar coordinates of the second point into Cartesian
		// and add with Cartesian coordinates of the first point
		x += polar.m_radius * cos(polar.m_angle);
		y += polar.m_radius * sin(polar.m_angle);

		// Convert Cartesian coordinates of the new point into polar
		Polar result;

		result.m_radius = sqrt(x * x + y * y);
		result.m_angle = atan2(y, x);

		return result;
	}

}
