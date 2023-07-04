#include "..\stdafx.h"

#include "seven_eight.h"

int main()
{
	Queue queue;

	//Add scenaries in methods
	
	queue.test_EmptyQueue();
	queue.test_AddElementsToQueue();
	queue.test_GetElementsFromQueue();
	queue.test_MaxSizeQueue();
	queue.test_OverflowQueue();
	queue.test_AnotherTypesQueue();

	return 0;
}

void Queue::putQueue(int element)
{

	if (isOverflow())
	{
		std::cout << "Overflow queue\n";
		exit(1);
	}
	else {
		if (m_Head == -1) m_Head = 0;
		m_Tail++;

		m_Queue[m_Tail] = element;
		std::cout << "Added queue element: " << element << "\n";
	}
}

int Queue::getQueue()
{
	int element;

	if (isEmpty())
	{
		std::cout << "Queue is empty \n";
		exit(1);
	}
	else {
		element = m_Queue[m_Head];

		if (m_Head >= m_Tail)
		{
			m_Head = -1;
			m_Tail = -1;
		}
		else m_Head++;

		std::cout << "Queue item removed: " << element << "\n";
		return element;
	}
		
	
}

void Queue::outQueue() const
{
	int i;
	if (isEmpty())
	{
		std::cout << "Queue is empty \n";
		exit(1);
	}
	else {
		std::cout << std::endl
			<< "Index front: " << m_Head;
		std::cout << std::endl
			<< "Elements: ";
		for (i = m_Head; i <= m_Tail; i++)
			std::cout << m_Queue[i] << "  ";
		std::cout << std::endl
			<< "Index tail: " << m_Tail << "\n";
	}
	

	
	
}

bool Queue::isOverflow() const {
	if (m_Head == 0 && m_Tail == k_MAX - 1) {
		return true;
	}
	return false;
}

bool Queue::isEmpty() const
{
	if (m_Head == -1)
		return true;
	else
		return false;
}



void Queue::test_EmptyQueue()
{
	getQueue();
}

void Queue::test_AddElementsToQueue()
{
	putQueue(8);
	putQueue(3);
	putQueue(4);
	putQueue(2);
	putQueue(1);

	outQueue();
}

void Queue::test_GetElementsFromQueue()
{
	putQueue(1);
	putQueue(2);
	putQueue(3);
	putQueue(4);

	outQueue();

	getQueue();

	outQueue();
}

void Queue::test_MaxSizeQueue()
{
	putQueue(1000);
	putQueue(227);
	putQueue(-300);
	putQueue(445);
	putQueue(5);

	outQueue();
}

void Queue::test_OverflowQueue()
{
	putQueue(1000);
	putQueue(227);
	putQueue(-300);
	putQueue(445);
	putQueue(5782);
	putQueue(5000); // Overflow

	outQueue();
}

void Queue::test_AnotherTypesQueue()
{
	putQueue(1000.0);
	putQueue(227);
	putQueue(445.0f);

	outQueue();
}

void Queue::test_Main()
{
	// Queue is empty
	getQueue();

	// Adds elements
	putQueue(8);
	putQueue(3);
	putQueue(4);
	putQueue(2);
	putQueue(1);

	outQueue();

	getQueue(); // Delete 1 element
	outQueue(); // The contents of the queue of four elements

	// Queue overflow
	putQueue(10);
}


