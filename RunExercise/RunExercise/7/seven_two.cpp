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

		// Check input, last value for '\0'
		if (countOfWorkers > 99) 
		{
			std::cout << "The program is finished. Reason: array overflow \n";
			exit(1);
		}

		std::cout << "Continue (y/n)?"; 
		std::cin >> choice;
	
	} while (choice != 'n');

	// Ouput data of array
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
	std::cin >> m_NameOfWorker;

	std::cout << "Input number of worker: "; 
	std::cin >> m_NumberOfWorker;
}

void Employee::putData()
{
	std::cout << "\n Name: " << m_NameOfWorker;
	std::cout << "\n Number: " << m_NumberOfWorker;
}