#include "12_10.h"


void Manager::getData()
{
	Employee::getData();
	std::cout << "Enter job title: "; std::cin >> m_job_title;
	std::cout << "Enter summ of contributon: "; std::cin >> m_dues;
}

void Manager::putData()
{
	Employee::putData();
	std::cout << "\n Job Title: " << m_job_title;
	std::cout << "\n Summ of contributon: " << m_dues;
}

void Scientist::getData()
{
	Employee::getData();
	std::cout << "Enter Count of publications: "; std::cin >> m_count_pubs;
}

void Scientist::putData()
{
	Employee::putData();
	std::cout << "\n Count of publications: " << m_count_pubs;
}


void Employee::add()
{
	char choice;
	std::cout << "'m' because add manager"
		"\n's' add scientist"
		"\n'l' add laborer"
		"\nYour choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case 'm': arr_ptr[count] = new Manager; break;
	case 's': arr_ptr[count] = new Scientist; break;
	case 'l': arr_ptr[count] = new Laborer; break;
	default: wcout << L"\nUnknown employee type\n"; return;
	}
	arr_ptr[count++]->getData();
}

void Employee::display()
{
	for (int i = 0; i < count; i++)
	{
		std::cout << (i + 1);
		switch (arr_ptr[i]->get_type())
		{
		case EEmployeeType::tManager: std::cout << " Type: manager"; 
			break;
		case EEmployeeType::tScientist: std::cout << " Type: scientist"; 
			break;
		case EEmployeeType::tLaborer: std::cout << " Type: laborer"; 
			break;
		default: std::cout << "Unknown type";
		}
		arr_ptr[i]->putData();
		std::cout << "\n";
	}
}

EEmployeeType Employee::get_type()
{
	if (typeid(*this) == typeid(Manager))
		return EEmployeeType::tManager;
	else if (typeid(*this) == typeid(Scientist))
		return EEmployeeType::tScientist;
	else if (typeid(*this) == typeid(Laborer))
		return EEmployeeType::tLaborer;
	else {
		std::cerr << "Unknown employee type"; exit(1);
	}

	return EEmployeeType::tManager;
}

// Read all objects from file
void Employee::read()
{
	int size; // Size of employee object
	EEmployeeType eType;
	ifstream readStream;

	readStream.open("Employee.wok", ios::binary);
	if (!readStream)
	{
		std::cout << "I cant open file\n"; return;
	}
	count = 0;

	// Read next type employee
	while (true)
	{
		readStream.read((char *)&eType, sizeof(eType));
		if (readStream.eof()) // If end from file
			break;
		if(!readStream)
		{
			std::cout << "I cant read employee type from file\n";
			return;
		}

		// Write a new empty employee-object to memory
		switch (eType)
		{
		case EEmployeeType::tManager:
			// Correct class type and calculate ist size
			arr_ptr[count] = new Manager;
			size = sizeof(Manager);
		break;
		case EEmployeeType::tScientist:
			arr_ptr[count] = new Scientist;
			size = sizeof(Scientist);
			break;
		case EEmployeeType::tLaborer:
			arr_ptr[count] = new Laborer;
			size = sizeof(Laborer);
			break;
		default: std::cout << "Unknown employee type from file\n";
			return;
		}

		// Read data to a employy-object from file
		readStream.read((char *)arr_ptr[count] + sizeof(void *), size - sizeof(void *));

		if (!readStream)
		{
			std::cout << "\nI cant read employee data from file\n"; return;
		}
		count++;
	}

	std::cout << "Amount of reading from file: " << count << " enployees\n";
}

// Write all objects to file
void Employee::write()
{
	int size; // Size of employee object
	std::cout << "Write to file: "<< count << " enployees\n";
	EEmployeeType eType;
	ofstream writeStream;

	writeStream.open("Employee.wok", ios::trunc | ios::binary);
	if (!writeStream)
	{
		std::cout << "I cant open file\n"; return;
	}

	// For everyone employees in the list
	for (int i = 0; i < count; i++) 
	{
		// Get his type
		eType = arr_ptr[i]->get_type();
		// Write employee's type
		writeStream.write((char *)&eType, sizeof(eType));

		switch (eType) // To Calculate size of employy-object 
		{
			case EEmployeeType::tManager:   size = sizeof(Manager);
				break;
			case EEmployeeType::tScientist: size = sizeof(Scientist);
				break;
			case EEmployeeType::tLaborer:	size = sizeof(Laborer);
				break;
			default:
				break;
		}

		writeStream.write((char *)(arr_ptr[i]) + sizeof(void *), size - sizeof(void *));

		if(!writeStream)
		{
			std::cout << "\nI cant write employee to file\n"; return;
		}
	}
}

// Find employee at the number
void Employee::find()
{
	unsigned long number;
	std::cout << "Enter the number of the employee u are looking for \n";
	std::cin >> number;

	Employee *employee;
	int size;
	EEmployeeType eType;
	ifstream readStream;

	readStream.open("Employee.wok", ios::binary);
	if (!readStream)
	{
		std::cout << "I cant open file\n"; return;
	}

	while (true)
	{
		readStream.read((char *)&eType, sizeof(eType));
		if (readStream.eof()) // If end from file
			break;
		if (!readStream)
		{
			std::cout << "I cant read employee type from file\n";
			return;
		}

		// Write a new empty employee-object to memory
		switch (eType)
		{
		case EEmployeeType::tManager:
			// Correct class type and calculate ist size
			employee = new Manager;
			size = sizeof(Manager);
			break;
		case EEmployeeType::tScientist:
			employee = new Scientist;
			size = sizeof(Scientist);
			break;
		case EEmployeeType::tLaborer:
			employee = new Laborer;
			size = sizeof(Laborer);
			break;
		default: std::cout << "Unknown employee type from file\n";
			return;
		}

		readStream.read((char *)employee + sizeof(void *), size - sizeof(void *));

		if (!readStream)
		{
			std::cout << "\nI cant read employee data from file\n"; return;
		}
		
		
		if (employee->m_id == number) // If founded
		{
			switch (employee->get_type())
			{
			case EEmployeeType::tManager: std::cout << " Type: manager";
				break;
			case EEmployeeType::tScientist: std::cout << " Type: scientist";
				break;
			case EEmployeeType::tLaborer: std::cout << " Type: laborer";
				break;
			default: std::cout << "Unknown type";
			}
			employee->putData();
			std::cout << "\n";
		}
		else {
			delete employee;
		}
		std::cout << "An employee with this number has not been found.\n";
	}
}


int main12_10()
{
	char choice;

	while (true) 
	{
		wcout << "'a' - Add an employee in the list"
			"\n'd' - Display all employees to the screen"
			"\n'w' - Write all employees to file"
			"\n'r' - Read all employees from file"
			"\n'f' - Find number of employee from file"
			"\n'e' - Exit"
			"\nYour choice: ";

		std::cin >> choice;
		switch (choice)
		{
		case 'a': Employee::add();
			break;
		case 'd': Employee::display();
			break;
		case 'w': Employee::write();
			break;
		case 'r': Employee::read();
			break;
		case 'f': Employee::find();
			break;
		case 'e': exit(0);
			break;
		default: std::cout << "Unknown command";
			break;
		}
	}

	return 0;
}