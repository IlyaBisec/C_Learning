#pragma once

// Added Data class and another classes from ex9_1

#include "..\stdafx.h"

namespace NineEight
{
	class Date
	{
	public:
		void getData();
		void displayData() const;

	private:
		int m_day, m_month, m_year;
	};

	class Publication
	{
	public:
		void getData();
		void displayData() const;

	private:
		char m_title[LENGTH];
		float m_price;
	};
	
	class Publication2 : public Publication
	{
	public:
		void getData();
		void displayData() const;
	private:
		Date m_publicationDate;
	};

	class Book : public Publication2
	{
	public:
		void getData();
		void displayData() const;

	private:
		int m_countOfPages;
	};

	class Type : Publication2
	{
	public:
		void getData();
		void displayData() const;

	private:
		float m_recordTime;	// recording time in minutes
	};
}