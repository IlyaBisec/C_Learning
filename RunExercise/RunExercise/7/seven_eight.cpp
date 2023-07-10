#include "..\stdafx.h"

#include "seven_eight.h"

int main()
{
	Queue queue;

	//Add scenaries in methods
	
	/*queue.test_EmptyQueue();
	queue.test_AddElementsToQueue();
	queue.test_GetElementsFromQueue();
	queue.test_MaxSizeQueue();
	queue.test_OverflowQueue();
	queue.test_AnotherTypesQueue();*/

	queue.test_scen1();
	queue.test_scen2();
	queue.test_scen3();


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
	// Queue size = 5

	putQueue(8);
	putQueue(3);
	putQueue(4);
	putQueue(2);
	putQueue(1);

	outQueue();
}

void Queue::test_GetElementsFromQueue()
{
	// Queue size = 5

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
	// Queue size = 5

	putQueue(1000);
	putQueue(227);
	putQueue(-300);
	putQueue(445);
	putQueue(5);

	outQueue();
}

void Queue::test_OverflowQueue()
{
	// Queue size = 5

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
	// Queue size = 5

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

// Scenaries
void Queue::test_scen1()
{
	// Queue size = 10

	// Puts = 3 
	putQueue(1000);
	putQueue(2000);
	putQueue(3000); 

	// Gets = 2
	getQueue();
	getQueue(); 

	// Puts =  4 
	putQueue(5000);
	putQueue(6000);
	putQueue(7000);
	putQueue(8000);

	// Gets = 5
	getQueue();
	getQueue();
	getQueue();
	getQueue();
	getQueue();

	// Queue's size = 0
	// Puts = 9 
	putQueue(112);
	putQueue(121);
	putQueue(131);
	putQueue(141);
	putQueue(151);
	putQueue(161);
	putQueue(171);
	putQueue(181);
	putQueue(191);

	// Gets = 2
	getQueue();
	getQueue();

	// Puts = 3 
	putQueue(1111);
	putQueue(231);
	putQueue(4444);

	// Queue's size = 10
	// Summ = 18

}

void Queue::test_scen2()
{
	// Queue size = 10

	// Puts = 3 
	putQueue(1000);
	putQueue(2000);
	putQueue(3000);

	// Gets = 2
	getQueue();
	getQueue();

	// Puts =  4 
	putQueue(5000);
	putQueue(6000);
	putQueue(7000);
	putQueue(8000);

	// Gets = 5
	getQueue();
	getQueue();
	getQueue();
	getQueue();
	getQueue();

	// Queue's size = 0
	// Puts one more 9
	for (int i = 1; i <= 9; i++)
		putQueue(i);

	putQueue(-1111); 
	// Overflow exception, program exit
	putQueue(10000);

	// Summ = 16, 17'st - overfow
}

void Queue::test_scen3()
{
	// Queue size = 10

	// Puts = 3 
	putQueue(1000);
	putQueue(2000);
	putQueue(3000);

	// Gets = 2
	getQueue();
	getQueue();

	// Puts =  4 
	putQueue(5000);
	putQueue(6000);
	putQueue(7000);
	putQueue(8000);

	// Gets = 5
	getQueue();
	getQueue();
	getQueue();
	getQueue();
	getQueue();

	// Queue's size = 0
	// Puts one more 7
	for (int i = 1; i <= 7; i++)
		putQueue(i);

	// Gets 8 elements
	getQueue();
	getQueue();
	getQueue();
	getQueue();
	getQueue();
	getQueue();
	getQueue();
	// Empty exception, program exit
	// Puts 14
	// Gets 15
	getQueue();

}