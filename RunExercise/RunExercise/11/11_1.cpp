#include "11_1.h"

namespace chapter_11 
{
	void Book::getData()
	{
		Publication::getData();

		std::cout << "Input count of page: ";
		std::cin >> m_countPage;
	}

	void Book::putData() const
	{
		Publication::putData();

		std::cout << "Count of page: " << m_countPage << "\n";
	}

	void Type::getData()
	{
		Publication::getData();

		std::cout << "Input recording time in minutes: ";
		std::cin >> m_recordTime;
	}

	void Type::putData() const
	{
		Publication::putData();

		std::cout << "Recording time in minutes: " << m_recordTime << "\n";
	}

}

int main11_1()
{
	chapter_11::Publication *pubPtr[100];
	int n = 0;
	char choice;

	do {
		std::cout << "Input book or audio? (b/a): ";
		std::cin >> choice;
		if (choice == 'b') {
			pubPtr[n] = new chapter_11::Book;
		} else {
			pubPtr[n] = new chapter_11::Type;
		}
		std::cout << "Input publication data " << n + 1 << ":";
		pubPtr[n++]->getData();
		std::cout << "\nInput next publication? (y/n): ";
		std::cin >> choice;
		std::cout << std::endl;
	} while (choice == 'y');


	for (int j = 0; j < n; j++) {
		std::cout << "Publication data " << j + 1 << ":";
		pubPtr[j]->putData();
	}

	return 0;
}