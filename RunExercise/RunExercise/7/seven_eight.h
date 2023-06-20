// Simple queue demonstrate

 #pragma once

class Queue
{

public:
	Queue() { m_Head = -1;  m_Tail = -1; m_Length = 0; }
	
	// Puts to queue, push analog
	void putQueue(int element);
	// Shows results
	void outQueue()const;
	// Gets from queue
	int  getQueue();

	//Checks Queue status
	bool isOverflow() const;
	bool isEmpty() const;
	
private:

	enum { k_MAX = 5 };

	int m_Queue[k_MAX];
	int m_Head, m_Tail;
	int m_Length;
};
