#include "seven_three.h"

int main3()
{
	Distance distArray[100];   // 100 objects type of Distance
	Distance total(0, 0.0),
			 average;		   // average value
	
	int countOfInputValue = 0; // count of input value 
	char choice;			   // choice user

	do {
		std::cout << "\nInput distance: ";
		distArray[countOfInputValue++].getDistance();
		
		std::cout << "Continue (y/n)?";
		std::cin >> choice;
	} while (choice != 'n');

	// add up all the distances
	for (int i = 0; i < countOfInputValue; i++)
		total.addDistance(total, distArray[i]);

	//divide by a number
	average.divideDistance(total, countOfInputValue);
	std::cout << "\nAverage: ";

	average.showDistance();
	std::cout << "\n";

	return 0;
}

void Distance::getDistance()
{
	std::cout << "\nInput foot: ";
	std::cin >> mFeet;

	std::cout << "\nInput inches: ";
	std::cin >> mInches;
}

void Distance::showDistance() const
{
	std::cout << mFeet << "\'-" << mInches << '\"';
}

void Distance::addDistance(Distance d2, Distance d3)
{
	mInches = d2.mInches + d3.mInches;
	mFeet = 0;
	if (mInches >= 12.0)
	{
		mInches -= 12.0;
		mFeet++;
	}
	mFeet += d2.mFeet + d3.mFeet;
}

void Distance::divideDistance(Distance d2, int divisor)
{
	//convert to float
	float fitFeet = d2.mFeet + d2.mInches / 12.0;

	fitFeet /= divisor;
	mFeet = int(fitFeet); //get feet
	mInches = (fitFeet = mFeet) * 12.0; //get inches
}
