#pragma once

class Queue
{
private:

	enum { MAX = 10 };
	int mStack[MAX];
	int mHead, mTail;

public:

	Queue() { mHead = mTail = 0; }
	
	// put to stack
	void putQueue(int valueOfQueue);
	// get from stack
	int getQueue();

};