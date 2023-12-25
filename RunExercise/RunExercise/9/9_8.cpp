#include "9_8.h"

using namespace NineEight;

int main9_8()
{
	Book book;
	Type type;

	std::cout << "Input published book data\n";
	book.getData();
	std::cout << "Input published audio book data\n";
	type.getData();

	// Outputing to display
	std::cout << "Published book data\n";
	book.displayData();
	std::cout<< "Published audio book data\n";
	type.displayData();

	return 0;
}

namespace NineEight
{
	void Date::getData()
	{
		std::cout << "Input D.M.Y: \n";
		std::cin >> m_day >> m_separate >> m_month >> m_separate >> m_year;
	}
	void Date::displayData() const
	{
		std::cout << m_day << "." << m_month << "." << m_year << "\n";
	}

	void Publication::getData()
	{
		std::cout << "Input title: ";
		std::cin.get(m_title, LENGTH);

		std::cout << "Input price: ";
		std::cin >> m_price;
	}
	void Publication::displayData() const
	{
		std::cout << "Title: " << m_title << "\n";
		std::cout << "Price: " << m_price << "\n";
	}
	
	void Publication2::getData()
	{
		Publication::getData();

		std::cout << "Input date of publication: ";
		m_publicationDate.getData();
		
		std::cout<< "\n";
	}
	void Publication2::displayData() const
	{
		Publication::displayData();

		std::cout << "Date of publication: ";
		m_publicationDate.displayData();

		std::cout << "\n";
	}

	void Book::getData()
	{
		Publication2::getData();

		std::cout << "Input count of page: ";
		std::cin >> m_countOfPages;
	}
	void Book::displayData() const
	{
		Publication2::displayData();

		std::cout << "Count of page: " << m_countOfPages << "\n";
	}

	void Type::getData()
	{
		Publication2::getData();

		std::cout << "Input recording time in minutes: ";
		std::cin >> m_recordTime;
	}
	void Type::displayData() const
	{
		Publication2::displayData();

		std::cout << "Recording time in minutes: " << m_recordTime << "\n";
	}
}