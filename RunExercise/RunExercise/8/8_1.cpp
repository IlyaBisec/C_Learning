#include "8_1.h"

int main8_1()
{

	Distance distanceOne,
			 distanceThree, distanceFour;

	distanceOne.getDistance();

	Distance distanceTwo(11, 6.25); 

	distanceThree = distanceOne - distanceTwo;
	distanceFour = distanceOne + distanceTwo + distanceThree;

	std::cout << "distance 1: "; 
	distanceOne.showDistance(); std::cout << "\n";

	std::cout << "distance 2: ";
	distanceTwo.showDistance(); std::cout << "\n";

	std::cout << "distance 3: ";
	distanceThree.showDistance(); std::cout << "\n";

	std::cout << "distance 4: ";
	distanceFour.showDistance(); std::cout << "\n";

	return 0;
}

Distance Distance::operator + (Distance distance) const
{
	int feet = mFeet + distance.mFeet;
	float inches = mInches + distance.mInches;

	if (inches >= 12.0)
	{
		inches -= 12.0;
		feet++;
	}

	return Distance(feet, inches);
}

Distance Distance::operator - (Distance distance) const
{
	int feet = mFeet - distance.mFeet;
	float inches = mInches - distance.mInches;

	if (inches < 0)
	{
		feet--;
		inches += 12.0;
	}

	return Distance(feet, inches);
}