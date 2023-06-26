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
		std::cin >> m_Day >> m_Month >> m_Year;
	}
	void Date::displayData() const
	{
		std::cout << m_Day << "." << m_Month << "." << m_Year << "\n";
	}

	void Publication::getData()
	{
		std::cout << "Input title: ";
		std::cin.get(m_Title, LENGTH);

		std::cout << "Input price: ";
		std::cin >> m_Price;
	}
	void Publication::displayData() const
	{
		std::cout << "Title: " << m_Title << "\n";
		std::cout << "Price: " << m_Price << "\n";
	}
	
	void Publication2::getData()
	{
		Publication::getData();

		std::cout << "Input date of publication: ";
		publicationDate.getData();
		
		std::cout<< "\n";
	}
	void Publication2::displayData() const
	{
		Publication::displayData();

		std::cout << "Date of publication: ";
		publicationDate.displayData();

		std::cout << "\n";
	}

	void Book::getData()
	{
		Publication2::getData();

		std::cout << "Input count of page: ";
		std::cin >> m_CountOfPages;
	}
	void Book::displayData() const
	{
		Publication2::displayData();

		std::cout << "Count of page: " << m_CountOfPages << "\n";
	}

	void Type::getData()
	{
		Publication2::getData();

		std::cout << "Input recording time in minutes: ";
		std::cin >> m_RecordTime;
	}
	void Type::displayData() const
	{
		Publication2::displayData();

		std::cout << "Recording time in minutes: " << m_RecordTime << "\n";
	}
}