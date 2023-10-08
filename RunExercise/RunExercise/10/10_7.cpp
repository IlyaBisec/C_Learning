#include "10_7.h"

int main10_7()
{
	TenSeven::Person *ptr_Person[100];

	int numberOfPeople = 0; // Number of people in the array
	char choice;

	do
	{
		ptr_Person[numberOfPeople] = new TenSeven::Person;
		cout << "Subject: " << numberOfPeople << "\n";

		ptr_Person[numberOfPeople]->setData();
		numberOfPeople++;
		cout << "Continue(y/n)?";
		cin >> choice;

	} while (choice == 'y');

	cout << "Not sorted list: ";
	TenSeven::printList(ptr_Person, numberOfPeople);

	TenSeven::salSort(ptr_Person, numberOfPeople);
	
	cout << "Sorted list: ";
	TenSeven::printList(ptr_Person, numberOfPeople);

	return 0;
}

namespace TenSeven {
	
	void Person::setData()
	{
		cout << "Input name: "; cin >> m_name; cout;
		cout << "Input salary: "; cin >> m_salary; cout << "\n";
	}
	void Person::printData() const
	{
		cout << "Name: " << m_name<<"\n";
		cout << "Salary: " << m_salary << "\n";
	}
	float Person::getSalary() const
	{
		return m_salary;
	}

	// The salSort(); function for sorting pointers in the array
	// pointers to objects of the Person class according to the 
	// size of salaries
	void salSort(Person **ptr_Person, int ptr_Size)
	{
		for (int i = 0; i < ptr_Size - 1; i++) {
			for (int j = i + 1; j < ptr_Size; j++)
			{
				// Comparing people's salaries
				if ((*(ptr_Person + i))->getSalary() > (*(ptr_Person + j))->getSalary())
				{
					Person *ptr_tempPerson = *(ptr_Person + i);
					*(ptr_Person + i) = *(ptr_Person + j);
					*(ptr_Person + j) = ptr_tempPerson;
				}
			}
		}
	}
	
	// Displays a list of people entered by the user
	void printList(Person **ptr_Person, int ptr_Size)
	{
		for (int i = 0; i < ptr_Size; i++)
		{
			cout << endl << "Subject: " + i;
			(*(ptr_Person + i))->printData();
		}
		cout << "\n";
	}
}