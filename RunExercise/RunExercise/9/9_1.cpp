#include "9_1.h"

int main9_1()
{
	Publication publication;
	Book fantasyBook;
	Type type;

	std::cout << "Input data...\n";

	//publication.getData();
	//fantasyBook.getData();
	type.getData();

	std::cout << "\nEntered data: \n";

	//publication.putData();
	//fantasyBook.putData();
	type.putData();

	return 0;
}

void Publication::getData()
{
	std::cout << "Input title: ";
	std::cin.get(p_title, LENGTH);

	std::cout << "Input price: ";
	std::cin>>p_price;
}

void Publication::putData() const
{
	std::cout << "Title: " << p_title << "\n";
	std::cout << "Price: " << p_price << "\n";
}

void Book::getData()
{
	Publication::getData();

	std::cout << "Input count of page: ";
	std::cin>>m_countPage;
}

void Book::putData() const
{
	Publication::putData();

	std::cout << "Count of page: " << m_countPage << "\n";
}

void Type::getData()
{
	Book::getData();

	std::cout << "Input recording time in minutes: ";
	std::cin >> m_recordTime;
}

void Type::putData() const
{
	Book::putData();

	std::cout << "Recording time in minutes: " << m_recordTime << "\n";
}
