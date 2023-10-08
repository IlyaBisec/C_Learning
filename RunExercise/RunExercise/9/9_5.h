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
		char m_name[LENGTH];
		unsigned long m_number;
	};

	class Manager : public Employee
	{
	public:
		Manager():m_dues(0){}
		
		void getData();
		void putData() const;

	private:
		char m_title[LENGTH]; // Manager's position
		double m_dues;		  // Sum of dues at the golf club
	};

	class Scientist : public Employee
	{
	public:
		Scientist() :m_publications(0) {}

		void getData();
		void putData() const;
	private:
		int m_publications;	// Count of publications
	};

	class Laborer :public Employee
	{
	
	};

	// Defence of modification the source class
	
	class EmployeeClone: public Employee
	{
	public:
		EmployeeClone() :m_compensations(0) {}

		void getData();
		void putData() const;

	private:
		double m_compensations;

		enum EPaymentPeriod
		{
			Hourly, 
			Weekly,
			Monthly
		};
		EPaymentPeriod paymentPeriod;
	};

	class ManagerClone : public EmployeeClone
	{
	public:
		ManagerClone() :m_dues(0) {}

		void getData();
		void putData() const;

	private:
		char m_title[LENGTH]; // Manager's position
		double m_dues;		  // Sum of dues at the golf club
	};

	class ScientistClone : public EmployeeClone
	{
	public:
		ScientistClone() :m_publications(0) {}

		void getData();
		void putData() const;
	private:
		int m_publications;	// Count of publications
	};

	class LaborerClone :public EmployeeClone
	{

	};
}