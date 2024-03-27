// There is a linklist class from the example in Chapter 10.
// It is required to write a program that gives the user 4 possibilities:
// 
//  1. add an item to the list in memory (in this case, the user enters the data
//     that will be stored in the list item);
//  2. display the items of the list in memory;
//  3. write the data of all the list items to a file on disk; 
//  4. extract data from a file, create a linked list in memory and write
//	   data from the file to it.

#include "pre12.h"

namespace chapter12_8
{
	struct Link // Element of linklist
	{
		int data;   // Data
		Link *next; // Pointer on the next element of linklist
	};

	class Linklist
	{
	public:
		Linklist() { m_first = NULL; }

		void addItem(int data); // 1
		void display() const;	// 2

		void writeToFile();     // 3
		void readFromFile();    // 4

	private:
		Link *m_first;
	};

	void Linklist::addItem(int data)
	{
		Link *newLink = new Link;
		newLink->data = data;
		newLink->next = m_first;

		m_first = newLink;
	}
	void Linklist::display() const
	{
		Link *current = m_first;
		while(current)
		{
			std::cout << current->data << "\n";
			current = current->next;
		}
	}
	
	void Linklist::writeToFile()
	{
		std::ofstream file("Link.spi", std::ios::trunc | std::ios::binary);
		if(!file)
		{
			std::cerr << "Error opennig file!\n";
			exit(1);
		}
		// Reading the list items in memory
		Link *current = m_first;
		while(current)
		{
			file.write(reinterpret_cast<char *>(&current->data), sizeof(current->data));
			current = current->next;
		}
	}
	void Linklist::readFromFile()
	{
		std::ifstream file;
		file.open("Link.spi", std::ios::ate | std::ios::binary);
		if(!file)
		{
			std::cerr << "Error opennig file!\n";
			exit(1);
		}
		// Deleting an old list in memory
		Link *current = m_first;
		while(current)
		{
			m_first = current->next;
			delete current;
			current = m_first;
		}
		// Reading data from a file and writing it to a newly created list
		int data;
		int elementSize = sizeof(data);
		int elementNum = (int)file.tellg() / elementSize;
		for(int i = elementNum; i > 0; i--)
		{
			file.seekg(-elementSize, std::ios::cur);
			file.read(reinterpret_cast<char *>(&data), elementSize);
			addItem(data);
			file.seekg(-elementSize, std::ios::cur);
		}
	}
}

using namespace chapter12_8;

int main12_8()
{
	Linklist linklist;
	char choice; 

	while (true)
	{
		std::cout << 
			"'a' - add an item to a list in memory\n"
			"'s' - display the data of the list items in memory\n"
			"'w' - write the data of the list items to a file\n"
			"'r' - read data from a file and write it to a list in memory\n"
			"'e' - exit\n"
			"Your choice: ";
		std::cin >> choice;
		switch (choice)
		{
		case 'a':          // Add an item to a list in memory
			std::cout << "Enter the data for the list item: ";
			int data; std::cin >> data;
			linklist.addItem(data); break;
		case 's':          // Display the data of the list items in memory
			linklist.display(); break;
		case 'w':          // Write the data of the list items to a file
			linklist.writeToFile(); break;
		case 'r':          // Read data from a file and write it to a list in memory
			linklist.readFromFile(); break;
		case 'e': exit(0); // exit
		default: std::cout << "Unknown command\n";
		}
	}

	return 0;
}