#include "seven_three.h"

int main()
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
	std::cin >> feet;

	std::cout << "\nInput inches: ";
	std::cin >> inches;
}

void Distance::showDistance() const
{
	std::cout << feet << "\'-" << inches << '\"';
}

void Distance::addDistance(Distance d2, Distance d3)
{
	inches = d2.inches + d3.inches;
	feet = 0;
	if (inches >= 12.0)
	{
		inches -= 12.0;
		feet++;
	}
	feet += d2.feet + d3.feet;
}

void Distance::divideDistance(Distance d2, int divisor)
{
	//convert to float
	float fitFeet = d2.feet + d2.inches / 12.0; 

	fitFeet /= divisor;
	feet = int(fitFeet); //get feet
	inches = (fitFeet = feet) * 12.0; //get inches
}
