#include "14_3.h"

using namespace Template_14_3;


template <class Q>
void Queue<Q>::put(Q value)
{
	// If Overflow
	if (m_length == MAX)
	{
		std::cout << "Overflow queue max size is " << MAX << "\n";
		exit(1);
	}

	// If before adding element the end of the queue
	// coincides with the end of the array
	if (m_tail == MAX - 1)
	{
		m_tail = -1;
	}

	m_queue[++m_tail] = value;
	m_length++;
}

template <class Q>
Q Queue<Q>::get()
{
	// If queue is empty
	if (m_length == 0)
	{
		std::cout << "Queue is empty, I can't get element!";
		exit(1);
	}

	Q temp = m_queue[m_head++];
	m_length--;

	// If  before extracting, the index of the start queue has gone
	// beyond the end of the array
	if (m_head == MAX)
	{
		m_head = 0;
	}
	return temp;
}

template <class Q>
void Queue<Q>::display() const
{
	if (m_length == 0)
		std::cout << "Empty";

	for (int i = 0; i < m_length; i++)
	{
		if (m_head + i < MAX)
		{
			std::cout << m_queue[m_head + i] << ' ';
		}
		else
		{
			std::cout << m_queue[m_head + i - MAX] << ' ';
		}
	}
}

int main_14_3()
{
	Queue<int> queue;
	int element;
	char choice;
	int actionNumber;

	do
	{
		std::cout << "Choose an action: 1 - put, 2 - get: ";
		std::cin >> actionNumber;

		// Try start action with queue
		try
		{
			switch (actionNumber)
			{
				// Put in the queue
			case 1: 
				std::cout << "Enter a value of element: ";
				std::cin >> element;
				queue.put(element);
				break;
				// Get from the queue
			case 2:
				std::cout << "Value of the entering element: "<<
					queue.get()<<"\n";
				break;
			default:
				std::cout << "Unknown number. Try more\n\n";
				choice = 'y'; 
				continue;
			}
		}
		catch (Queue<int>::Full error)
		{
			std::cout << "Error, queue is overflow " << error.max_size << "\n";
			std::cout << "Action isn't selected\n";
		}
		catch (Queue<int>::Empty error)
		{
			std::cout << "Error, queue is empty \n";
			std::cout << "Action isn't selected\n";
		}

		// Get queue content
		std::cout << "Queue content: ";
		queue.display();
		std::cout << "\n";

		// Exit
		std::cout << "Do you want to work with the queue again?(y/n): ";
		std::cin >> choice;
		std::cout << "\n";

	} while (choice == 'y');

	return 0;
}