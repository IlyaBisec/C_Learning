// SafeArray with template, because put any types
#ifndef _SAFEARRAY_TEMPLATE_H_
#define _SAFEARRAY_TEMPLATE_H_
#endif // !_SAFEARRAY_TEMPLATE_H_
#pragma once

#include <iostream>

constexpr int SIZE = 3;

namespace Template_14_6
{
	template <class S>
	class SafeArray
	{
	public:
		S &operator[] (int index)
		{
			if (index < 0 || index >= SIZE)
			{
				std::cout << "Error index\n";
				exit(1);
			}
			return m_array[index];
		}

	private:
		S m_array[SIZE];
	};
}
