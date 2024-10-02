// Using exclusion in the model queue with help template

#ifdef _TEMPLATE_EXCLUSION_H_
#define _TEMPLATE_EXCLUSION_H_
#endif // _TEMPLATE_EXCLUSION_H_

#pragma once

#include <iostream>

namespace Template_14_3 {

	template <class Q>
	class Queue
	{
	public:
		Queue() { m_head = 0, m_length = 0, m_tail = -1; }

		void put(Q value);
		Q get();
		void display() const;

		// Class of Exclusion
		class Full
		{
		public:
			Full() { max_size = MAX; }
			
			// Max queue size
			int max_size; 
		};
		// Class of Exclusion
		class Empty{};

	private:
		static const int MAX = 10;
		Q m_queue[MAX];

		int m_head,
			m_tail,
			m_length;
	};

}

