#include "9_4.h"

int main()
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
		std::cout << "Input tittle: ";
		std::cin.get(p_Title, LENGTH);

		std::cout << "Input price: ";
		std::cin >> p_Price;
	}

	void Publication::putData() const
	{
		std::cout << "Tittle: " << p_Title << "\n";
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

	void Book::getData()
	{
		Publication::getData();

		std::cout << "Input count of page: ";
		std::cin >> m_CountPage;
	}

	void Book::putData() const
	{
		Publication::putData();

		std::cout << "Count of page: " << m_CountPage << "\n";
	}

	void Type::getData()
	{

		std::cout << "Input recording time in minutes: ";
		std::cin >> m_RecordTime;

		Sales::getData();
	}

	void Type::putData() const
	{
		std::cout << "Recording time in minutes: " << m_RecordTime << "\n";

		Sales::putData();
	}

	void Disk::getData()
	{
		DiskType diskType;
		char choiceType;

		Publication::getData();

		std::cout << "Input the type of disk: ";
		std::cin >> choiceType;

		if (choiceType = 'c')
		{
			diskType = k_CD;
		}
		else diskType = k_DvD;

	}

	void Disk::putData() const
	{
		DiskType diskType;
		char choiceType;

		Publication::putData();

		std::cout << "Disk type: \n";

		if (choiceType = k_CD)
		{
			std::cout << "CD";
		}
		else 
		{
			std::cout << "DVD";
		}

	}
}