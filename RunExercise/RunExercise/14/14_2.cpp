#include "14_2.h"

using namespace Template_14_2;


template <class Q>
void Queue<Q>::put(Q value)
{
	// If Overflow
	if (m_length == MAX)
	{
		std::cout << "Overflow queue max size is " << MAX << "\n";
		exit(1);
	}

	// If before adding element the end of the queue
	// coincides with the end of the array
	if (m_tail == MAX - 1)
	{
		m_tail = -1;
	}

	m_queue[++m_tail] = value;
	m_length++;
}

template <class Q>
Q Queue<Q>::get()
{
	// If queue is empty
	if (m_length == 0)
	{
		std::cout << "Queue is empty, I can't get element!";
		exit(1);
	}

	Q temp = m_queue[m_head++];
	m_length--;

	// If  before extracting, the index of the start queue has gone
	// beyond the end of the array
	if (m_head == MAX)
	{
		m_head = 0;
	}
	return temp;
}

int main14_2()
{
	Queue<int> i_queue;
	i_queue.put(-2);
	i_queue.put(-1);
	i_queue.put(0);
	i_queue.put(2);

	std::cout << "int : " << i_queue.get() << " ";
	std::cout << i_queue.get() << " ";
	std::cout << i_queue.get() << " ";
	std::cout << i_queue.get() << "\n";

	Queue<double> d_queue;
	d_queue.put(0.2);
	d_queue.put(-12.2);
	d_queue.put(-133.9);

	std::cout << "\ndouble : " << d_queue.get() << " ";
	std::cout << d_queue.get() << " ";
	std::cout << d_queue.get() << "\n";

	Queue<char> c_queue;
	c_queue.put('T');
	c_queue.put('e');
	c_queue.put('S');
	c_queue.put('t');

	std::cout << "\nchar : " << c_queue.get() << " ";
	std::cout << c_queue.get() << " ";
	std::cout << c_queue.get() << " ";
	std::cout << c_queue.get() << "\n";

	return 0;
}