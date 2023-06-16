#include "..\stdafx.h"

#include "seven_eight.h"

int main()
{
	Queue queue;   
	
	
	std::cout << "Input number: \n";
	int userInput;
	std::cin >> userInput;
	for(int i = 0; i < userInput; i++)
		// Added elements to the queue
		queue.putQueue(i);
	// Added more items to the queue
	queue.putQueue(2);
	// Displayed the queue
	queue.outQueue(queue);
	// Displayed size of queue
	queue.sizeQueue();
	// Displayed the farthest element
	queue.frontQueue();
	// And the nearest element
	queue.backQueue();
	// Deleted element
	queue.popQueue();
	queue.outQueue(queue);
	queue.sizeQueue();

	return 0;
}

void Queue::putQueue(int valueOfQueue)
{
	if (m_Tail + 1 == m_Head || (m_Tail + 1 == k_MAX && !m_Head))
	{
		std::cout << "Overflow queue\n";
		exit(1);
	} 

	m_Tail++;
	if (m_Tail == k_MAX)
		m_Tail = 0;

	m_Queue[m_Tail] = valueOfQueue;
}

int Queue::popQueue()
{
	if (m_Head == m_Tail)
	{
		std::cout << "Queue is empty \n";
		return m_Queue[m_Head];
	} 
	m_Head++;
	if (m_Head == k_MAX)
	{
		m_Head = 0;
	}	
}

void Queue::sizeQueue()
{
	int size = 0;
	
	for (int i = m_Head; i < m_Tail; i++)
		size++;
	std::cout<<size<<"\n";
}

int Queue::frontQueue()
{
	std::cout << m_Queue[m_Tail] << "\n";;
	return m_Queue[m_Tail];
}

int Queue::backQueue()
{
	std::cout << m_Queue[m_Head + 1]<<"\n";
	return m_Queue[m_Head + 1];
}

void Queue::outQueue(const Queue& queue)
{
	for (int i = queue.m_Head + 1; i < queue.m_Tail + 1; i++)
	{
		std::cout << " " << queue.m_Queue[i];
	}
	std::cout <<"\n";
}

