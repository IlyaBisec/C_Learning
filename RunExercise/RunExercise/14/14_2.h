// Modeling queue using template
#pragma once

#ifndef _TEMPLATE_QUEUE_SYSTEM_H_
#define _TEMPLATE_QUEUE_SYSTEM_H_
#endif // !_TEMPLATE_QUEUE_SYSTEM_H_

#include <iostream>

namespace Template_14_2 {

	template <class Q>
	class  Queue
	{
	public:
		Queue() { m_head = 0, m_length = 0, m_tail = -1; }

		void put(Q value);
		Q get();

	private:
		static const int MAX = 10;
		Q m_queue[MAX];

		int m_head,
			m_tail,
			m_length;
	};

}