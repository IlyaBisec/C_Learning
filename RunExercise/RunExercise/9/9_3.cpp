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
	std::cin.get(p_title, LENGTH);

	std::cout << "Input price: ";
	std::cin >> p_price;
}

void NewPublication::putData() const
{
	std::cout << "Title: " << p_title << "\n";
	std::cout << "Price: " << p_price << "\n";
}

void Sales::getData()
{
	std::cout << "Please input total sum for last 3 months \n";

	std::cout << "Enter the sales revenue for 3 months (separated by a space): "<<"\n";
	std::cin >> totalSum[0] >> totalSum[1] >> totalSum[2];
	
}

void Sales::putData() const
{
	std::cout << "total sum for last 3 months: \n";
	std::cout << totalSum[0] << " " << totalSum[1] << " " << totalSum[2]<<std::endl;
	
}

void NewBook::getData()
{
	NewPublication::getData();

	std::cout << "Input count of page: ";
	std::cin >> m_countPage;

	Sales::getData();
}

void NewBook::putData() const
{
	NewPublication::putData();

	std::cout << "Count of page: " << m_countPage << "\n";

	Sales::putData();
}

void NewType::getData()
{

	std::cout << "Input recording time in minutes: ";
	std::cin >> m_recordTime;

	Sales::getData();
}

void NewType::putData() const
{
	std::cout << "Recording time in minutes: " << m_recordTime << "\n";
	
	Sales::putData();
}
