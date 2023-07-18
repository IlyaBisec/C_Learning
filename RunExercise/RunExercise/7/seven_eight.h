// Simple queue demonstrate

 #pragma once

// Refactor queue

class Queue
{

public:
	Queue() { m_Front =  m_Back = 0; //m_Length = 0;
	}
	
	// Puts to queue, push analog
	void putQueue(int element);
	// Shows results
	void outQueue()const;
	// Gets from queue
	int  getQueue();


	//Checks Queue status
	bool isOverflow() const;
	bool isEmpty() const;

	// Test methods
	// Creating an empty queue and checking that it is empty
	void test_EmptyQueue();
	
	// Adding items to the queue and checking their availability.
	void test_AddElementsToQueue();
	
	// Extracting items from the queue and checking their correctness
	void test_GetElementsFromQueue();
	
	// Checking the health of the queue when the maximum size is reached
	void test_MaxSizeQueue();
	
	// Checking work with a large number of elements
	void test_OverflowQueue();
	
	// Checking work with different types of data.
	void test_AnotherTypesQueue();

	void test_Main();

	void test_scen1();

	void test_scen2();

	void test_scen3();
	
private:

	enum { k_MAX = 5 };

	int m_Queue[k_MAX];
	int m_Front, m_Back, count;
	//int m_Length;
};


