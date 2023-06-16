// Simple queue demonstrate

 #pragma once

class Queue
{

public:
	Queue() { m_Head = m_Tail = 0; }
	
	// Puts to queue, push analog
	void putQueue(int valueOfQueue);
	// Shows results
	void outQueue(const Queue& queue);
	// Gets size of queue
	void sizeQueue();

	// Delete element from queue
	int popQueue();
	// Returns the farthest element of the queue
	int frontQueue();
	// Returns the nearest element of the queue
	int backQueue();

private:

	enum { k_MAX = 10 };

	int m_Queue[k_MAX];
	int m_Head, m_Tail;
};
