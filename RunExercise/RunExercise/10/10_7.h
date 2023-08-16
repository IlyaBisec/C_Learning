// Sorting objects through an array of pointers to them.
// Person - a class representing a person

#pragma once

#include "..\stdafx.h"

using namespace std;

namespace TenSeven {

	class Person
	{
	public:
		
		void setData();
		void printData() const;

		float getSalary() const;

	protected:

		string m_Name;
		float m_Salary;

	};

	// The salSort(); function for sorting pointers in the array
	// pointers to objects of the Person class according to the 
	// size of salaries
	void salSort(Person **ptr_Person, int ptr_Size);

	// Displays a list of people entered by the user
	void printList(Person **ptr_Person, int ptr_Size);
}
