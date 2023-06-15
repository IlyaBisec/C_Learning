#include "..\stdafx.h"

#include "seven_eight.h"

int main7_8()
{
	Queue queue;

	int temp = 12345;    

	queue.putQueue(7, temp);
	temp = queue.getQueue(7);

	std::cout << temp;

	queue.putQueue(-5, temp); // Error, overflow queue 

	return 0;
}

void Queue::putQueue(int index, int valueOfQueue)
{
	if ((index >= 0) && index < k_MAX)
	{
		m_Queue[index] = valueOfQueue;
	}
	else {
		std::cout << "\nOverflo array..index " << index << " Out of boder "
			<< k_MAX - 1;
		exit(1);
	}
}


int Queue::getQueue(int index)
{
	if ((index >= 0) && index < k_MAX)
	{
		return m_Queue[index];
	}
	else {
		std::cout << "Overflo array..index " << index << " Out of boder "
			<< k_MAX - 1;
		exit(1);
	}
	
}
