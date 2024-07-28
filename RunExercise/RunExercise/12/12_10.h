#pragma once
#include <io.h>
#include <fstream>
#include <iostream>

using namespace std;

const int LENGTH = 32;
const int MAX_COUNT = 100; // Max count of employers


enum class EEmployeeType { tManager, tScientist, tLaborer };


class Employee
{

public:
	virtual void getData()
	{
		std::cin.ignore(10, L'\n');
		std::cout << " Enter surname: "; std::cin >> m_surnamename;
		std::cout << " Enter number of employer: "; std::cin >> m_id;
	}
	virtual void putData() const
	{
		std::cout << "\n surname: " << m_surnamename;
		std::cout << "\n number of employer: " << m_id;
	}
	virtual EEmployeeType get_type();
	static void add();
	static void display();
	static void read(); // Read data from file
	static void write(); // Write data to file
	static void find();


private:
	char m_surnamename[LENGTH];
	unsigned long m_id;
	static int count; // Employers count             
	static Employee *arr_ptr[];
};

int Employee::count;
Employee *Employee::arr_ptr[MAX_COUNT];



class Manager : public Employee
{
public:
	void getData();
	void putData();

private:
	char m_job_title[LENGTH];
	double m_dues; // Summ of contributon
};


class Scientist : public Employee
{
public:
	void getData();
	void putData();

private:
	int m_count_pubs; // Count of publications
};

class Laborer : public Employee {};