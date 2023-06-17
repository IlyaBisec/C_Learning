#include "..\stdafx.h"

#include "seven_eight.h"

int main()
{
	Queue queue;   
	
	// Overflow queue
	queue.putQueue(8);
	queue.outQueue(queue);
	queue.getQueue(5);
	queue.outQueue(queue);
	queue.putQueue(6);
	queue.outQueue(queue);
	queue.putQueue(1);
	queue.outQueue(queue);

	 // Queue is empty
	queue.putQueue(8);
	queue.outQueue(queue);
	queue.getQueue(5);
	queue.outQueue(queue);
	queue.putQueue(6);
	queue.outQueue(queue);
	queue.getQueue(10);
	queue.outQueue(queue);
	queue.getQueue(1);
	queue.outQueue(queue);


	return 0;
}

void Queue::putQueue(int valueOfQueue)
{
	/*if (m_Length == k_MAX)
	{
		std::cout << "Overflow queue\n";
		exit(1);
	}*/

	// Filling
	for (int i = 0; i < valueOfQueue; i++) {
		m_Queue[++m_Tail] = i;
		m_Length++;

		if (m_Length == k_MAX)
		{
			std::cout << "Overflow queue\n";
			exit(1);
		}
	}

	// If end of queue == end of array
	// then it moves to the beginning of the array
	if (m_Tail == k_MAX - 1)
		m_Tail = -1;
}

void Queue::getQueue(int valueOfQueue)
{
	
	for (int i = 0; i < valueOfQueue; i++) {
		m_Queue[m_Head++] = i;
		m_Length--;

		if (m_Length == 0)
		{
			std::cout << "Queue is empty \n";
			exit(1);
		}
	}


	// If, after the queue element, the index of the beginning of the array
	// is located behind the end of the array, then it is moved to the beginning
	// of the array
	if (m_Head == k_MAX)
		m_Head = 0;
	
	//return valueOfQueue;
}

void Queue::outQueue(const Queue& queue)
{
	for (int i = queue.m_Head + 1; i < queue.m_Tail + 1; i++)
	{
		std::cout << " " << queue.m_Queue[i];
	}
	std::cout << "\n";
}



