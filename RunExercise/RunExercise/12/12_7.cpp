// There is a name class from exercise 6 to this 12th chapter. 
// It is required to rewrite this class, making the stream a static
// field of this class. The functionality should remain the same. 
// You need to add a static function to open the file and a static function 
// to set the file pointer to the beginning of the file.


#include "pre12.h"

namespace chapter12_7
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

		// Move the pointer to the beginning of the file for reading
		static void fileReset();
		// Opening a file on disk for writing and reading
		static void fileOpen();
		// The number of entries in the file
		static int noteCount();

	private:
		std::string m_name, m_fatherName, m_surName;
		unsigned long m_number;
		static std::fstream m_file;
	};

	// Defining a static class variable
	std::fstream Document::m_file;

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
		fileReset();
		int count = 1;
		while(m_file >> m_number >> m_name >> m_fatherName >> m_surName && count != recordCount)
		{
			recordCount++;
		}
	}

	void Document::fileWrite()
	{
		m_file << m_number<< ' ' << m_name << ' ' << m_fatherName << ' ' << m_surName << ' ';
	}

	void Document::fileReset()
	{
		m_file.seekg(0);
	}

	void Document::fileOpen()
	{
		m_file.open("note.md", std::ios::app | std::ios::out | std::ios::in);
		if(!m_file)
		{
			std::cerr << "Error opennig file!\n";
			exit(1);
		}
	}

	int Document::noteCount()
	{
		std::string name, fatherName, surName;
		unsigned long number;

		fileReset();
		int count = 0;

		while(m_file >> number >> name >> fatherName >> surName)
		{
			count++;
		}
		m_file.clear();
		return count;
	}
}

using namespace chapter12_7;

int main12_7()
{
	Document pasport;
	char choice;

	Document::fileOpen();

	do
	{
		pasport.getDocument();
		pasport.fileWrite();

		std::cout << "Continue? y/n ";
		std::cin >> choice;
		std::cout << "\n";

	} while (choice == 'y');

	int count = Document::noteCount();

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