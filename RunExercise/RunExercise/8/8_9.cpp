#include "8_9.h"

int main()
{
	Polar polarX, polarY, resultPolarCoordinate;
	Casterian coordinateX, coordinateY, resultCoordinate;

	polarX.getCoordinate();
	polarY.getCoordinate();

	coordinateX = polarX;
	coordinateY = polarY;

	resultCoordinate = coordinateX + coordinateY;
	resultPolarCoordinate = resultCoordinate;
	
	resultPolarCoordinate.displayPolar();

	return 0;
}



void Polar::getCoordinate()
{
	std::cout << "Input polar coordinate\n";
	std::cout << "Enter angle: \n";
	std::cin >> m_Angle;

	if (m_Angle < 0)
	{
		if (m_Angle > 360)
		{
			exit(1);
		}
	}
	std::cout << "Enter radius: \n";
	std::cin >> m_Radius;

}

void Polar::displayPolar()
{
	std::cout << "Current polar coordinate, after added\n";
	std::cout << "Angle: " << m_Angle << "\n";
	std::cout << "Radius: " << m_Radius << "\n";
}

double Polar::getAngle() const
{
	return m_Angle;
}

double Polar::getRadius() const
{
	return m_Radius;
}


Casterian Casterian::operator+(Casterian coordinate)
{
	double tempY = mY + coordinate.mY;
	double tempX = mX + coordinate.mX;
	
	return Casterian(tempX, tempY);
}

double Casterian::getCoordinateX() const
{
	return mX;
}

double Casterian::getCoordinateY() const
{
	return mY;
}

