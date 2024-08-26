// Generate index out exclusion class
// with message code
#ifndef _ARROVER_EXCLUSION_MOD_TEMPLATE_H_
#define _ARROVER_EXCLUSION_MOD_TEMPLATE_H_
#endif // !_ARROVER_EXCLUSION_MOD_TEMPLATE_H_
#pragma once

#include <iostream>

const int SIZE = 3;

namespace Template_14_9
{
	class SafeArray
	{
	public:
		class IndexOut 
		{
		public:
			int index;
			IndexOut(int i): index(i){}
		};

		int &operator[](int index)
		{
			if (index < 0 || index >= SIZE)
			{
				throw IndexOut(index);
			}
			return m_array[index];
		}
	private:
		int m_array[SIZE];
	};
}



