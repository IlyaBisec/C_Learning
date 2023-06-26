#pragma once

// Added Data class and another classes from ex9_1

#include "..\stdafx.h"

namespace NineEight
{
	const int LENGTH = 80;

	class Date
	{
	public:
		void getData();
		void displayData() const;

	private:
		int m_Day, m_Month, m_Year;
	};

	class Publication
	{
	public:
		void getData();
		void displayData() const;

	private:
		char m_Title[LENGTH];
		float m_Price;
	};
	
	class Publication2 : public Publication
	{
	public:
		void getData();
		void displayData() const;
	private:
		Date publicationDate;
	};

	class Book : public Publication2
	{
	public:
		void getData();
		void displayData() const;

	private:
		int m_CountOfPages;
	};

	class Type : Publication2
	{
	public:
		void getData();
		void displayData() const;

	private:
		float m_RecordTime;	// recording time in minutes
	};
}