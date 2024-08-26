// The amax() function get max value of the element of array
#pragma once
#ifndef _AMAX_TEMPLATE_H_
#define _AMAX_TEMPLATE_H_
#endif // !_AMAX_TEMPLATE_H_

namespace Template_14_5
{
	template <class A>
	A amax(A *array, int size)
	{
		A temp = array[0];
		for (int i = 1; i < size; i++)
		{
			if (temp < array[i])
			{
				temp = array[i];
			}
		}
		return temp;
	}
}