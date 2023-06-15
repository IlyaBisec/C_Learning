// Multiple inheritance with avoiding
// modification of source classes

#pragma once

#include "..\stdafx.h"

namespace NineThree {

	const int LENGTH = 80;

	// Source class

	class Employee
	{
	public:
		void getData();
		void putData() const;

	private:
		char m_Name[LENGTH];
		unsigned long m_Number;
	};

	class Manager : public Employee
	{
	public:
		Manager():m_Dues(0){}
		
		void getData();
		void putData() const;

	private:
		char m_Title[LENGTH]; // Manager's position
		double m_Dues;		  // Sum of dues at the golf club
	};

	class Scientist : public Employee
	{
	public:
		Scientist() :m_Publications(0) {}

		void getData();
		void putData() const;
	private:
		int m_Publications;	// Count of publications
	};

	class Laborer :public Employee
	{
	
	};

	// Defence of modification the source class
	
	class EmployeeClone: public Employee
	{
	public:
		EmployeeClone() :m_Compensations(0) {}

		void getData();
		void putData() const;

	private:
		double m_Compensations;

		enum PaymentPeriod
		{
			k_hourly, 
			k_weekly,
			k_monthly
		};
		PaymentPeriod paymentPeriod;
	};

	class ManagerClone : public EmployeeClone
	{
	public:
		ManagerClone() :m_Dues(0) {}

		void getData();
		void putData() const;

	private:
		char m_Title[LENGTH]; // Manager's position
		double m_Dues;		  // Sum of dues at the golf club
	};

	class ScientistClone : public EmployeeClone
	{
	public:
		ScientistClone() :m_Publications(0) {}

		void getData();
		void putData() const;
	private:
		int m_Publications;	// Count of publications
	};

	class LaborerClone :public EmployeeClone
	{

	};
}