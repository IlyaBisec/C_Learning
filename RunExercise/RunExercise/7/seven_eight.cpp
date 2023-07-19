#include "..\stdafx.h"

#include "seven_eight.h"

int main()
{
	Queue queue;

	queue.test_scen5();

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
		std::cout << "Added queue element: " << element << "\n";
		
		m_Back = (m_Back + 1) % k_SIZE;
		m_QueueArray[m_Back] = element;
		m_Count++;
	}
}

void Queue::getInfo()
{
	std::cout << "\n";
	std::cout << "The front element is " << getFront() << "\n";
	std::cout << "The queue size is " << getSize() << "\n";
	std::cout << "\n";
}

int Queue::getQueue()
{

	if (isEmpty())
	{
		std::cout << "Queue is empty \n";
		exit(1);
	}
	else {
		int element = m_QueueArray[m_Front];
		std::cout << "Queue item removed: " << element << "\n";

		m_Front = (m_Front + 1) % k_SIZE;
		m_Count--;

		return element;
	}
}

int Queue::getFront()
{
	if (isEmpty())
	{
		std::cout << "Queue is empty \n";
		exit(1);
	}

	return m_QueueArray[m_Front];
}

int Queue::getSize() const
{
	return m_Count;
}

bool Queue::isOverflow() const {
	return (getSize() == k_SIZE);
}

bool Queue::isEmpty() const
{
	return (getSize() == 0);
}



void Queue::test_scen1()
{
	//getQueue();

	putQueue(1);
	putQueue(2);
	putQueue(3);
	putQueue(4);
	putQueue(5);
	//putQueue(56);

	getInfo();

	getQueue();
	getQueue();
	getQueue();

	putQueue(6);
	putQueue(7);
	putQueue(8);

	getInfo();

	getQueue();
	getQueue();
	getQueue();

	putQueue(9);
	putQueue(10);
	putQueue(11);

	getInfo();

	getQueue();
	getQueue();
	getQueue();
	getQueue();

	getInfo();
}

void Queue::test_scen2()
{
	//getQueue();

	putQueue(1);
	putQueue(2);
	putQueue(3);
	putQueue(4);
	putQueue(5);
	//putQueue(56);

	getQueue();
	getQueue();
	getQueue();
	getQueue();
	getQueue();

	putQueue(6);

	getInfo();

	getQueue();

	putQueue(7);
	putQueue(8);
	putQueue(9);

	getInfo();

	getQueue();
	getQueue();
	getQueue();

	getInfo();

	getQueue();

	getInfo();
}

void Queue::test_scen3()
{
	//getQueue();

	putQueue(1);
	putQueue(2);
	//putQueue(56);

	getQueue();

	putQueue(3);
	putQueue(4);

	getInfo();

	getQueue();
	getQueue();

	putQueue(7);
	putQueue(8);
	putQueue(9);

	getInfo();

	getQueue();
	getQueue();
	getQueue();

	getInfo();

	getQueue();

	getInfo();
}

void Queue::test_scen4()
{
	//getQueue();

	putQueue(1);

	getQueue();

	putQueue(2);
	putQueue(3);

	getInfo();

	getQueue();

	putQueue(4);
	putQueue(5);
	putQueue(6);

	getInfo();

	getQueue();
	getQueue();

	putQueue(7);
	putQueue(8);
	putQueue(9);
	putQueue(10);

	getInfo();

	getQueue();

	getInfo();
}

void Queue::test_scen5()
{
	//getQueue();

	putQueue(1);

	getInfo();

	putQueue(2);

	getInfo();

	getQueue();

	putQueue(3);
	putQueue(4);

	getInfo();

	getQueue();
	getQueue();

	getInfo();

	putQueue(7);
	putQueue(8);
	putQueue(9);
	putQueue(10);

	getInfo();

	getQueue();
	getQueue();
	getQueue();

	getInfo();

	putQueue(11);
	putQueue(12);
	putQueue(13);

	getInfo();

	getQueue();
	getQueue();
	getQueue();
	getQueue();

	getInfo();

	putQueue(14);
	putQueue(15);
	putQueue(16);
	putQueue(17);

	getInfo();

	getQueue();
	getQueue();
	getQueue();
	getQueue();
	getQueue();

	getInfo();

	putQueue(18);

	getQueue();
	getQueue();
	getQueue();
	getQueue();
	getQueue();
	getQueue();
}