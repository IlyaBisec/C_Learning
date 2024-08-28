// Generate index out exclusion class
#ifndef _ARROVER_EXCLUSION_TEMPLATE_H_
#define _ARROVER_EXCLUSION_TEMPLATE_H_
#endif // !_ARROVER_ENCLUSION_TEMPLATE_H_
#pragma once

#include <iostream>

constexpr int SIZE = 3;

namespace Template_14_8
{
	class SafeArray
	{
	public:
		class IndexOut{};

		int &operator[](int index)
		{
			if (index < 0 || index >= SIZE)
			{
				throw IndexOut();
			}
			return m_array[index];
		}
	private:
		int m_array[SIZE];
	};
}



