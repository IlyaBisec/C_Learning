#pragma once

// Create new executive class, who include high
// manager, and this class child of manager

#include "..\stdafx.h"

namespace NineNine
{
	class Student
	{
	public:
		void getData();
		void putData() const;

	private:
		char m_nameSchool[LENGTH];
		char m_degree[LENGTH];
	};

	class Employee
	{
	public:
		void getData();
		void putData() const;

	private:
		char m_name[LENGTH];
		unsigned long m_number;
	};

	class Manager : public Employee, private Student
	{
	public:
		Manager() :m_dues(0) {}

		void getData();
		void putData() const;

	private:
		char m_title[LENGTH]; // Manager's position
		double m_dues;		  // Sum of dues at the golf club
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
		Scientist() :m_publications(0) {}

		void getData();
		void putData() const;
	private:
		int m_publications;	// Count of publications
	};

	class Laborer :public Employee
	{

	};
}