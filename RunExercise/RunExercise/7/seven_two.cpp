#include "seven_two.h"

int main7_2()
{
	Employee employer[100];
	
	int countOfWorkers = 0;
	char choice;

	do 
	{
		std::cout << "Input data of worker with number: " << countOfWorkers+1;
		employer[countOfWorkers++].getData();
		
		std::cout << "Continue (y/n)?"; 
		std::cin >> choice;
	
	} while (choice != 'n');

	// ouput data of array
	for (int i = 0; i < countOfWorkers; i++)
	{
		std::cout << "\nNumber of worker " << i+1;
		employer[i].putData();
	}
	std::cout << "\n";

	return 0;
}


void Employee::getData()
{
	std::cout << "\nInput name of worker: "; 
	std::cin >> mNameOfWorker;

	std::cout << "Input number of worker: "; 
	std::cin >> mNumberOfWorker;
}

void Employee::putData()
{
	std::cout << "\n Name: " << mNameOfWorker;
	std::cout << "\n Number: " << mNumberOfWorker;
}