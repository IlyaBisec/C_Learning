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
		std::cin >> m_Radius;

		if (m_Radius < 0) {
			std::cout << "Radius < 0!\n";
			exit(1);
		}

		if (radians)
		{
			std::cout << "Input angle in the radians: ";
			std::cin >> m_Angle;
		}
		else
		{
			std::cout << "Input angle in the degrees: ";
			int tempDeg;
			std::cin >> tempDeg;
			m_Angle = tempDeg * PI / 180;
		}
	}

	void Polar::putData(bool radians) const
	{
		std::cout << "Radius: " << m_Radius << "\n";

		if (radians)
			std::cout << "Angle in the radians: " << m_Angle << "\n";
		else
			std::cout << "Angle in the degrees: " << m_Angle * PI / 180 << "\n";


	}

	Polar Polar::operator+(const Polar &polar) const
	{
		// Convert polar coordinates of the first point into Cartesian
		double x = m_Radius * cos(m_Angle);
		double y = m_Radius * sin(m_Angle);

		// Convert the polar coordinates of the second point into Cartesian
		// and add with Cartesian coordinates of the first point
		x += polar.m_Radius * cos(polar.m_Angle);
		y += polar.m_Radius * sin(polar.m_Angle);

		// Convert Cartesian coordinates of the new point into polar
		Polar result;

		result.m_Radius = sqrt(x * x + y * y);
		result.m_Angle = atan2(y, x);

		return result;
	}

}
