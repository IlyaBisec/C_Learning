// Simple queue demonstrate

 #pragma once

// Refactor queue

class Queue
{

public:
	Queue() 
	{ 
		m_front = 0;
		m_back = -1;
		m_count = 0;
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
	int m_front, m_back, 
		m_count;			  // Current size of queue

};


