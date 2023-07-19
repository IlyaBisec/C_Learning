// Simple queue demonstrate

 #pragma once

// Refactor queue

class Queue
{

public:
	Queue() 
	{ 
		m_Front = 0;
		m_Back = -1;
		m_Count = 0;
	}
	
	// Puts to queue, push analog
	void putQueue(int element);
	// Gets from queue
	int  getQueue();
	// Returns the first element
	int getFront();
	// Returns size of queue
	int getSize() const;

	void getInfo();

	//Checks Queue status
	bool isOverflow() const;
	bool isEmpty() const;

	// Scenaries
	void test_scen1(); // Alexander test
	void test_scen2();
	void test_scen3();
	void test_scen4();
	void test_scen5();

private:
	enum { k_SIZE = 5 }; // Max size of queue

	int m_QueueArray[k_SIZE]; // Array for storing elements of queue
	int m_Front, m_Back, 
		m_Count;			  // Current size of queue

};


