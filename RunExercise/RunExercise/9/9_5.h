// Multiple inheritance with avoiding
// modification of source classes

#pragma once

#include "..\stdafx.h"

namespace NineThree {

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

	// Defence of modification the source class

	class EmployeeClone : public Employee {
	public:
		EmployeeClone() : m_compensations(0) {}

		void getData();
		void putData() const;

	private:
		double m_compensations;

		enum class EPaymentPeriod {
			Hourly,
			Weekly,
			Monthly
		};
		EPaymentPeriod paymentPeriod;
	};

	class Manager : public EmployeeClone
	{
	public:
		Manager():m_dues(0){}
		
		void getData();
		void putData() const;

	private:
		char m_title[LENGTH]; // Manager's position
		double m_dues;		  // Sum of dues at the golf club
	};

	class Scientist : public EmployeeClone
	{
	public:
		Scientist() :m_publications(0) {}

		void getData();
		void putData() const;
	private:
		int m_publications;	// Count of publications
	};

	class Laborer : public EmployeeClone
	{
	
	};

	

}