#include "9_4.h"

int main9_4()
{
	NineFour::Book fantasyBook;
	NineFour::Type type;
	NineFour::Disk disk;

	std::cout << "Input data...\n";

	fantasyBook.getData();
	type.getData();
	disk.getData();

	std::cout << "\nEntered data: \n";

	fantasyBook.putData();
	type.putData();
	disk.putData();

	return 0;
}

namespace NineFour {

	void Publication::getData()
	{
		std::cout << "Input title: ";
		std::cin.get(p_title, LENGTH);

		std::cout << "Input price: ";
		std::cin >> p_price;
	}

	void Publication::putData() const
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

	void Book::getData()
	{
		Publication::getData();

		std::cout << "Input count of page: ";
		std::cin >> m_countPage;
		Sales::getData();
	}

	void Book::putData() const
	{
		Publication::putData();

		std::cout << "Count of page: " << m_countPage << "\n";
		Sales::putData();
	}

	void Type::getData()
	{
		Publication::getData();
		std::cout << "Input recording time in minutes: ";
		std::cin >> m_recordTime;

		Sales::getData();
	}

	void Type::putData() const
	{
		Publication::putData();
		std::cout << "Recording time in minutes: " << m_recordTime << "\n";

		Sales::putData();
	}

	void Disk::getData()
	{
		char choiceType;

		Publication::getData();

		std::cout << "Input the type of disk: ";
		std::cin >> choiceType;

		switch (choiceType) 
		{
		case 'c':
			diskType = EDiskType::CD;
			break;
		case 'd':
			diskType = EDiskType::DVD;
			break;
		default:
			diskType = EDiskType::CD;
			break;
		}

		Sales::getData();
	}

	void Disk::putData() const
	{
		Publication::putData();

		std::cout << "Disk type: \n"<<((diskType == EDiskType::CD) ? "CD":"DVD")<<std::endl;
		Sales::putData();
	}
}