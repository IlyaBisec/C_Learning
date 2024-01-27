#include "11_4.h"

namespace chapter_11_4 {

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

	bool Book::isOversize() const { return (m_countPage > 900) ? true : false; }
	bool Type::isOversize() const { return (m_recordTime > 90) ? true : false; }

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


int main11_4()
{
	chapter_11_4::Publication *ptr_pub[100];
	int n = 0;
	char user_choice;

	do {
		std::cout << "Input book or audio? (b/a): "; std::cin >> user_choice;
		if (user_choice == 'b')      
			ptr_pub[n] = new chapter_11_4::Book; 
		else                      
			ptr_pub[n] = new chapter_11_4::Type; 
		std::cout << "Input publication data " << n + 1 << ":";
		ptr_pub[n++]->getData();   
		std::cout << "\nInput next publication? (y/n): "; std::cin >> user_choice; std::cout << std::endl;
	} while (user_choice == 'y'); 

	// Output data
	for (int j = 0; j < n; j++)
	{
		std::cout << "Publication data " << j + 1 << ":";
		ptr_pub[j]->putData();

		// If oversize
		if (ptr_pub[j]->isOversize()) std::cout << " (The size is too big!)\n";
	}

	return 0;
}