#include "14_10.h"

void Template_14_10::Distance::get()
{
	std::string tempString;

	while (true)
	{
		std::cout << "Enter feet: ";
		// Skip space symbols
		std::cin.unsetf(std::ios::skipws);
		std::cin >> tempString;
		
		// If enter feet is true
		if (isFeet(tempString))
		{
			// Clear lost unread symbols
			std::cin.ignore(10, '\n');
			m_feet = atoi(tempString.c_str());
			break;
		}

		std::cin.clear();
		std::cin.ignore(10, '\n');

		throw Exclusion(1);
	}

	while (true)
	{
		std::cout << "Enter inches: ";
		// Skip space symbols
		std::cin.unsetf(std::ios::skipws);
		std::cin >> m_inches;

		// If inches >= 12 or < 0
		if (m_inches >= 12.0 || m_inches < 0.0)
		{
			throw Exclusion(2);
			// Clear lost unread symbols
			std::cin.clear(std::ios::failbit);
		}
		// If Success
		if (std::cin.good())
		{
			std::cin.ignore(10, '\n');
			break;
		}
		std::cin.clear();
		std::cin.ignore(10, '\n');

		throw Exclusion(3);
	}
}

int Template_14_10::isFeet(std::string string)
{
	int stringLength = string.size();

	if (stringLength == 0 || stringLength > 5)
	{
		throw Distance::Exclusion(4);
	}

	for (int i = 0; i < stringLength; i++)
	{
		if ((string[i] < '0' || string[i] > '9') &&
			string[i] != '-')
		{
			throw Distance::Exclusion(5);
		}
	}

	double number = atof(string.c_str());

	if (number < -999.0 || number > 999.0)
	{
		throw Distance::Exclusion(6);
	}
	return 1;
}

using namespace Template_14_10;

int main14_10()
{
	try
	{
		Distance distance(1.17, 06.00);
	}
	catch (Distance::Exclusion error)
	{
		switch (error.errorNumber)
		{
		case 7:
			std::cout << "Count of feet will be: -999 to 999\n";
			break;
		case 8:
			std::cout << "Count of inches will be: >= 0 and < 12\n";
			break;
		default:
			break;
		}
	}

	// Get distance from user
	Distance distance;
	char answer;

	do
	{
		try
		{
			distance.get();
		}
		catch (Distance::Exclusion error)
		{
			switch (error.errorNumber)
			{
			case 1:
				std::cout << "get(): Feet will be integer and < 1000\n";
				break;
			case 2:
				std::cout << "get(): Inches will be between 0.0 and 11.99\n";
				std::cin.clear();
				std::cin.ignore(10, '\n');
				break;
			case 3:
				std::cout << "get(): Inches uncorrect\n";
				break;
			case 4:
				std::cout << "isFeet(): Input is empty or very enough symbols\n";
				std::cin.clear();
				std::cin.ignore(10, '\n');
				break;
			case 5:
				std::cout << "isFeet(): Count of feet can content digits or the '-' sign only\n";
				std::cin.clear();
				std::cin.ignore(10, '\n');
				break;
			case 6:
				std::cout << "isFeet(): Count of feet will be: -999 to 999\n";
				std::cin.clear();
				std::cin.ignore(10, '\n');
				break;
			}
			std::cout << "Enter again \n";
			answer = 'y'; 
			continue;
		}

		std::cout << "Interval = ";
		distance.show();
		std::cout << "And more? (y/n): ";
		std::cin >> answer;
		std::cin.ignore(10, '\n');

	} while (answer != 'n');

	return 0;
}