// Simple queue demonstrate

 #pragma once

class Queue
{

public:
	Queue() { m_Head = m_Tail = 0; }
	
	// Put to stack
	void putQueue(int valueOfQueue);
	// Get from stack
	int getQueue();

private:

	enum { MAX = 10 };
	int m_Stack[MAX];
	int m_Head, m_Tail;

};
