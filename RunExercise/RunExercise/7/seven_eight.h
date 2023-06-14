#pragma once

class Queue
{

public:
	Queue() { m_Head = m_Tail = 0; }
	
	// put to stack
	void putQueue(int valueOfQueue);
	// get from stack
	int getQueue();

private:

	enum { MAX = 10 };
	int m_Stack[MAX];
	int m_Head, m_Tail;

};