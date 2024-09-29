// Arithmetical tamplate which return average all 
// of the arithmetical elements array

#pragma once
#ifndef _ARITHMETICAL_TEMPLATE_H_
#define _ARITHMETICAL_TEMPLATE_H_



#include <iostream>

namespace Template_14_1{
	template <class T>
	T average(T * array, int size)
	{
		double sum = 0;

		for (int i = 0; i < size; i++)
		{
			sum += array[i];
		}

		return sum / size;
	}
}

#endif