#include "..\stdafx.h"

#include "seven_eight.h"

int main7_8()
{
	Queue queue;

	//Add scenaries in methods

	// Queue is empty
	queue.getQueue();
	
	// Adds elements
	queue.putQueue(8);
	queue.putQueue(3);
	queue.putQueue(4);
	queue.putQueue(2);
	queue.putQueue(1);

	queue.outQueue();

	queue.getQueue(); // Delete 1 element
	queue.outQueue(); // The contents of the queue of four elements
	

	// Queue overflow
	queue.putQueue(10);

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

		std::cout << "Queue item removed: "<<element << "\n";
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
	if (m_Length == k_MAX || m_Head == 0 && m_Tail == k_MAX - 1) {
		return true;
	}
	return false;
}

bool Queue::isEmpty() const
{
	if (m_Length == 0 || m_Head == -1)
		return true;
	else
		return false;
}


