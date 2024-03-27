// The addition of the class from exercise 4 of chapter 12
// Added methods:
// 
//	fileWrite(); - writes data to the end of the file
//	fileRead(int writeNumber); - retrieves data by the specified record number
// 
// When working with files, formatted input is used and
// output

#include "pre12.h"

namespace chapter12_6
{
	// A class that provides information about a person
	// Full name, number
	class Document
	{
	public:
		void getDocument();
		void showDocument() const;

		// Reading data from a file by record number
		void fileRead(int recordCount);
		// Writing data to the end of the file
		void fileWrite();
		// The number of entries in the file
		static int noteCount();

	private:
		std::string m_name, m_fatherName, m_surName;
		unsigned long m_number;

	};

	void Document::getDocument()
	{
		std::cout << "Enter number: "; std::cin >> m_number;
		std::cout << "Enter name, father name, surname: "; 
		std::cin >> m_name>>m_fatherName>>m_surName;
	}

	void Document::showDocument() const
	{
		std::cout << "Person " <<' '<<m_number << ": " << m_name << ' ' << m_fatherName << ' ' << m_surName << "\n";
	}

	void Document::fileRead(int recordCount)
	{
		std::ifstream file("note.md");
		
		if(!file)
		{
			std::cerr << "Error opennig file for reading!\n";
			exit(1);
		}

		int count = 1;
		while(file >> m_number >> m_name >> m_fatherName >> m_surName && count != recordCount)
		{
			recordCount++;
		}
	}

	void Document::fileWrite()
	{
		std::ofstream file("note.md");
		if(!file)
		{
			std::cerr << "Error opennig file!\n";
			exit(1);
		}
		file << m_number<< ' ' << m_name << ' ' << m_fatherName << ' ' << m_surName << ' ';
	}

	int Document::noteCount()
	{
		std::ifstream file("note.md");
		if(!file)
		{
			std::cerr << "Error opennig file for reading!\n";
			exit(1);
		}

		std::string name, fatherName, surName;
		unsigned long number;
		int count = 0;

		while(file >> number >> name >> fatherName >> surName)
		{
			count++;
		}
		return count;
	}
}

int main12_6()
{
	chapter12_6::Document pasport;
	char choice;

	do
	{
		pasport.getDocument();
		pasport.fileWrite();

		std::cout << "Continue? y/n ";
		std::cin >> choice;
		std::cout << "\n";

	} while (choice == 'y');

	int count = chapter12_6::Document::noteCount();

	std::cout << "\n In file: " << count << " notes\n";
	for (int i = 0; i <= count; i++)
	{
		std::cout << "\nNote " << i << "\n";
		pasport.fileRead(i);
		pasport.showDocument();
	}
	std::cout << "\n";
	
	return 0;
}

