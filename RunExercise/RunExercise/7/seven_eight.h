// Simple queue demonstrate

 #pragma once

class Queue
{

public:
	Queue() { m_Head = 0;  m_Tail = 0; m_Length = 0; }
	
	// Puts to queue, push analog
	void putQueue(int valueOfQueue);
	// Shows results
	void outQueue(const Queue& queue);
	// Gets from queue
	void getQueue(int valueOfQueue);


private:

	enum { k_MAX = 10 };

	int m_Queue[k_MAX];
	int m_Head, m_Tail;
	int m_Length;
};
