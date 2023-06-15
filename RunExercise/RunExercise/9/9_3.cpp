#include "9_3.h"


int main9_3()
{
	NewBook fantasyBook;
	NewType type;

	std::cout << "Input data...\n";

	fantasyBook.getData();
	type.getData();

	std::cout << "\nEntered data: \n";

	fantasyBook.putData();
	type.putData();

	return 0;
}

void NewPublication::getData()
{
	std::cout << "Input title: ";
	std::cin.get(p_Title, LENGTH);

	std::cout << "Input price: ";
	std::cin >> p_Price;
}

void NewPublication::putData() const
{
	std::cout << "Title: " << p_Title << "\n";
	std::cout << "Price: " << p_Price << "\n";
}

void Sales::getData()
{
	std::cout << "Please input total sum for last 3 months \n";

	for (int i = 1; i <= COUNT_MONTH; i++)
	{
		std::cout << "Month: " << i << "\n";
		std::cin >> totalSum[i];
	}
}

void Sales::putData() const
{
	std::cout << "total sum for last 3 months: "
		<< totalSum << "\n";
}

void NewBook::getData()
{
	NewPublication::getData();

	std::cout << "Input count of page: ";
	std::cin >> m_CountPage;

	Sales::getData();
}

void NewBook::putData() const
{
	NewPublication::putData();

	std::cout << "Count of page: " << m_CountPage << "\n";

	Sales::putData();
}

void NewType::getData()
{

	std::cout << "Input recording time in minutes: ";
	std::cin >> m_RecordTime;

	Sales::getData();
}

void NewType::putData() const
{
	std::cout << "Recording time in minutes: " << m_RecordTime << "\n";
	
	Sales::putData();
}
