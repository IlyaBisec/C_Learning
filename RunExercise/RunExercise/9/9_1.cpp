#include "9_1.h"

int main9_1()
{
	Publication publication;
	Book fantasyBook;
	Type type;

	std::cout << "Input data...\n";

	publication.getData();
	fantasyBook.getData();
	type.getData();

	std::cout << "\nEntered data: \n";

	publication.putData();
	fantasyBook.putData();
	type.putData();

	return 0;
}

void Publication::getData()
{
	std::cout << "Input title: ";
	std::cin.get(p_Title, LENGTH);

	std::cout << "Input price: ";
	std::cin>>p_Price;
}

void Publication::putData() const
{
	std::cout << "Title: " << p_Title << "\n";
	std::cout << "Price: " << p_Price << "\n";
}

void Book::getData()
{
	std::cout << "Input count of page: ";
	std::cin>>m_CountPage;
}

void Book::putData() const
{
	std::cout << "Count of page: " << m_CountPage << "\n";
}

void Type::getData()
{
	std::cout << "Input recording time in minutes: ";
	std::cin >> m_RecordTime;
}

void Type::putData() const
{
	std::cout << "Recording time in minutes: " << m_RecordTime << "\n";
}
