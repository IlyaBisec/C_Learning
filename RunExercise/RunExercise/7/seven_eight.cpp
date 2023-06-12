#include "..\stdafx.h"

#include "seven_eight.h"

int main8()
{
	Queue queue;

	queue.putQueue(10);
	queue.putQueue(20);

	std::cout << "Queue 1: " << queue.getQueue() << std::endl;
	std::cout << "Queue 2: " << queue.getQueue() << std::endl;

	return 0;
}

void Queue::putQueue(int valueOfQueue)
{
	mStack[mTail++] = valueOfQueue;
	if (mHead > 0)
	{	
		mHead--;
	}
	//mHead > 0 ? mHead-- : cout<<"error head \n";
}

int Queue::getQueue()
{
	if (mTail > 0)
	{
		mTail--;
	}

	return mStack[mHead++];
}
