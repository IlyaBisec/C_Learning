// Simple queue demonstrate

 #pragma once

class Queue
{

public:
	Queue() { m_Head = m_Tail = 0; }
	
	// Puts to queue
	void putQueue(int index,int valueOfQueue);
	// Gets from queue
	int getQueue(int index);

private:

	enum { k_MAX = 10 };
	int m_Queue[k_MAX];
	int m_Head, m_Tail;

};
