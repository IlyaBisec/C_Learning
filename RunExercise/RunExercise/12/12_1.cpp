// Getting user's data for read/write in file

#include "pre12.h"

namespace chapter12_1{

	class Distance
	{
	public:
		Distance() : m_feet(0), m_inches(0.0){}
		Distance(int feet, float inches) : m_feet(feet), m_inches(inches){}

		void getDistance()
		{
			std::cout << "\nInput foot: ";
			std::cin >> m_feet;

			std::cout << "Input inches: ";
			std::cin >> m_inches;
		}

		void showDistance() const
		{
			std::cout << m_feet << "\'|" << m_inches << '\"';
		}

	private:
		int m_feet;
		float m_inches;
	};

}


int main12_1()
{
	char choice;

	chapter12_1::Distance distance;
	std::fstream file;

	file.open("DISTANCE.DAT", std::ios::app | std::ios::out |
		                      std::ios::in | std::ios::binary);

	do
	{
		std::cout << "Enter interval data\n";
		distance.getDistance();

		file.write(reinterpret_cast<char *>(&distance), sizeof(distance));
		std::cout << "Continue? y/n ";
		std::cin >> choice;
		std::cout << "\n";

	} while (choice == 'y');

	file.seekg(0);
	file.read(reinterpret_cast<char *>(&distance), sizeof(distance));
	int count = 0;
	
	// End in file
	while (!file.eof())        
	{
		std::cout << "interval " << ++count << ": "; 
		distance.showDistance(); std::cout << std::endl;
		
		// Next interval
		file.read(reinterpret_cast<char *>(&distance), sizeof(distance));
	}

	return 0;
}

