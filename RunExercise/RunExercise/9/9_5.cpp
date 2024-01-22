#include "9_5.h"

int main9_5()
{
	// Source
	NineThree::Manager manager, manager2;
	NineThree::Scientist scientist;
	NineThree::Laborer laborer;

	// Input

	std::cout << "Input info about the manager\n";
	manager.getData();

	std::cout << "Input info about the manager 2\n";
	manager2.getData();

	std::cout << "Input info about the scientist\n";
	scientist.getData();

	std::cout << "Input info about the laborer\n";
	laborer.getData();


	// Output

	std::cout << "Output info about the manager\n";
	manager.putData();

	std::cout << "Output info about the manager 2\n";
	manager2.putData();

	std::cout << "Output info about the scientist\n";
	scientist.putData();

	std::cout << "Output info about the laborer\n";
	laborer.putData();


	return 0;
}

namespace NineThree
{
	// Source

	void NineThree::Employee::getData()
	{
		std::cout << "Enter name: ";
		std::cin.get(m_name, LENGTH);

		std::cout << "Enter number: ";
		std::cin >> m_number;
		std::cout << "\n";
	}

	void NineThree::Employee::putData() const
	{
		std::cout << "Name: "<<m_name<<"\n";
		std::cout << "Number: " << m_number << "\n";
	}

	void NineThree::Manager::getData()
	{
		EmployeeClone::getData();

		std::cout << "Enter title of manager: ";
		std::cin.get(m_title, LENGTH);

		std::cout << "Enter dues at the golf club: ";
		std::cin >> m_dues;
		std::cout << "\n";
	}

	void NineThree::Manager::putData() const
	{
		EmployeeClone::putData();

		std::cout << "Title of mananer: " << m_title << "\n";
		std::cout << "Dues: " << m_dues << "\n";
	}

	void NineThree::Scientist::getData()
	{
		EmployeeClone::getData();

		std::cout << "Enter count of publications: ";
		std::cin >> m_publications;
		std::cout << "\n";
	}

	void NineThree::Scientist::putData() const
	{
		EmployeeClone::putData();

		std::cout << "Count of publications: " << m_publications << "\n";
	}

	// Defence of modification the source class

	void NineThree::EmployeeClone::getData()
	{
		char userInputChoice;
		//PaymentPeriod paymentPeriod;

		Employee::getData();

		std::cout << "Enter compensations: ";
		std::cin >> m_compensations;

		std::cout << "Enter work payment period(the first letter";
		std::cout << " from hourly, weekly, monthly): \n";
		std::cin >> userInputChoice;

		switch (userInputChoice)
		{
		case 'h': paymentPeriod = EPaymentPeriod::Hourly;
			break;
		case 'w': paymentPeriod = EPaymentPeriod::Weekly;
			break;
		case 'm': paymentPeriod = EPaymentPeriod::Monthly;
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
		std::cout << m_compensations;

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

	

}
	