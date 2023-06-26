#pragma once

// Create new executive class, who include high
// manager, and this class child of manager

#include "..\stdafx.h"

namespace NineNine
{
	const int LENGTH = 80;

	class Student
	{
	public:
		void getData();
		void putData() const;

	private:
		char m_NameSchool[LENGTH];
		char m_Degree[LENGTH];
	};

	class Employee
	{
	public:
		void getData();
		void putData() const;

	private:
		char m_Name[LENGTH];
		unsigned long m_Number;
	};

	class Manager : public Employee, private Student
	{
	public:
		Manager() :m_Dues(0) {}

		void getData();
		void putData() const;

	private:
		char m_Title[LENGTH]; // Manager's position
		double m_Dues;		  // Sum of dues at the golf club
	};
	
	class Executive : private Manager
	{
	public:
		void getData();
		void putData() const;

	private:
		// The amount of the annual premium
		double m_yearlyBonus;
		
		// Number of shares
		unsigned long m_shares; 
	};

	class Scientist : public Employee, private Student
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
}