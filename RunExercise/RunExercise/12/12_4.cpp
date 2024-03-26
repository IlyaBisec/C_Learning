// Getting user's full name and write to file

#include "pre12.h"

int main12_4()
{
	std::string name, fatherName, surName;
	unsigned long number;
	char choice;

	std::ofstream file("Data.txt");
	
	do
	{
		std::cout << "Enter number: "; std::cin >> number;
		std::cout << "Enter name, father name, surname: "; 
		std::cin >> name>>fatherName>>surName;

		file << number << name << ' ' << fatherName << ' ' << surName << ' ';

		std::cout << "Continue? y/n ";
		std::cin >> choice;
		std::cout << "\n";

	} while (choice == 'y');

	std::ifstream data_file("Data.txt");
	while (data_file >> number >> name >> fatherName >> surName)
	{
		std::cout << "Person " <<' '<<number << ": " << name << ' ' << fatherName << ' ' << surName << "\n";
	}
	return 0;
}