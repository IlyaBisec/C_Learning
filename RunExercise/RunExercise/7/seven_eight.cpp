#include "..\stdafx.h"

#include "seven_eight.h"

int main7_8()
{
	Queue queue;

	queue.putQueue(10);
	queue.putQueue(20);

	std::cout << "Queue 1: " << queue.getQueue() << std::endl;
	std::cout << "Queue 2: " << queue.getQueue() << std::endl;

	return 0;
}

void Queue::putQueue(int valueOfQueue)
{
	m_Stack[m_Tail++] = valueOfQueue;
	if (m_Head > 0)
	{	
		m_Head--;
	}
	//mHead > 0 ? mHead-- : cout<<"error head \n";
}

int Queue::getQueue()
{
	if (m_Tail > 0)
	{
		m_Tail--;
	}

	return m_Stack[m_Head++];
}
