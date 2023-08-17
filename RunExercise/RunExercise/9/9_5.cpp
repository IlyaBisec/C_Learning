#include "9_5.h"

int main9_5()
{
	// Source
	NineThree::Manager manager;
	NineThree::Scientist scientist;
	NineThree::Laborer laborer;

	// Clones
	NineThree::ManagerClone managerClone;
	NineThree::ScientistClone scientistClone;
	NineThree::LaborerClone laborerClone;

	// Input

	std::cout << "Input info about the manager\n";
	manager.getData();

	std::cout << "Input info about the scientist\n";
	scientist.getData();

	std::cout << "Input info about the laborer\n";
	laborer.getData();

	// Clone

	std::cout << "Input info about the manager clone\n";
	managerClone.getData();

	std::cout << "Input info about the scientist clone\n";
	scientistClone.getData();

	std::cout << "Input info about the laborer clone\n";
	laborerClone.getData();

	// Output

	std::cout << "Output info about the manager\n";
	manager.putData();

	std::cout << "Output info about the scientist\n";
	scientist.putData();

	std::cout << "Output info about the laborer\n";
	laborer.putData();

	// Clone

	std::cout << "Output info about the manager\n";
	managerClone.putData();

	std::cout << "Output info about the scientist\n";
	managerClone.putData();

	std::cout << "Output info about the laborer\n";
	managerClone.putData();

	return 0;
}

namespace NineThree
{
	// Source

	void NineThree::Employee::getData()
	{
		std::cout << "Enter name: ";
		std::cin.get(m_Name, LENGTH);

		std::cout << "Enter number: ";
		std::cin >> m_Number;
		std::cout << "\n";
	}

	void NineThree::Employee::putData() const
	{
		std::cout << "Name: "<<m_Name<<"\n";
		std::cout << "Number: " << m_Number << "\n";
	}

	void NineThree::Manager::getData()
	{
		Employee::getData();

		std::cout << "Enter title of manager: ";
		std::cin.get(m_Title, LENGTH);

		std::cout << "Enter dues at the golf club: ";
		std::cin >> m_Dues;
		std::cout << "\n";
	}

	void NineThree::Manager::putData() const
	{
		Employee::putData();

		std::cout << "Title of mananer: " << m_Title << "\n";
		std::cout << "Dues: " << m_Dues << "\n";
	}

	void NineThree::Scientist::getData()
	{
		Employee::getData();

		std::cout << "Enter count of publications: ";
		std::cin >> m_Publications;
		std::cout << "\n";
	}

	void NineThree::Scientist::putData() const
	{
		Employee::putData();

		std::cout << "Count of publications: " << m_Publications << "\n";
	}

	// Defence of modification the source class

	void NineThree::EmployeeClone::getData()
	{
		char userInputChoice;
		//PaymentPeriod paymentPeriod;

		Employee::getData();

		std::cout << "Enter compensations: ";
		std::cin >> m_Compensations;

		std::cout << "Enter work payment period(the first letter";
		std::cout << " from hourly, weekly, monthly): \n";
		std::cin >> userInputChoice;

		switch (userInputChoice)
		{
		case 'h': paymentPeriod = Hourly;
			break;
		case 'w': paymentPeriod = Weekly;
			break;
		case 'm': paymentPeriod = Monthly;
			break;
		default: std::cout << "Error input"; exit(1);
			break;
		}
	}

	void NineThree::EmployeeClone::putData() const
	{
		char userInputChoice;
		//PaymentPeriod paymentPeriod;

		Employee::putData();

		std::cout << "Compensations: ";
		std::cout << m_Compensations;

		std::cout << "Payment period: \n";
		std::cin >> userInputChoice;

		switch (userInputChoice)
		{
		case 'h': std::cout << "Hourly";
			break;
		case 'w': std::cout << "Weekly";
			break;
		case 'm': std::cout << "Monthly";
			break;
		default: std::cout << "Error input"; exit(1);
			break;
		}
	}

	void NineThree::ManagerClone::getData()
	{
		Employee::getData();

		std::cout << "Enter title of manager: ";
		std::cin.get(m_Title, LENGTH);

		std::cout << "Enter dues at the golf club: ";
		std::cin >> m_Dues;
		std::cout << "\n";
	}

	void NineThree::ManagerClone::putData() const
	{
		Employee::putData();

		std::cout << "Title of mananer: " << m_Title << "\n";
		std::cout << "Dues: " << m_Dues << "\n";
	}

	void NineThree::ScientistClone::getData()
	{
		Employee::getData();

		std::cout << "Enter count of publications: ";
		std::cin >> m_Publications;
		std::cout << "\n";
	}

	void NineThree::ScientistClone::putData() const
	{
		Employee::putData();

		std::cout << "Count of publications: " << m_Publications << "\n";
	}

}
	