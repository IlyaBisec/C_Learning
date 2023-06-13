#pragma once

#include "..\stdafx.h"

class Sterling
{
private:
	long mPounds;
	int mShilling, mPens;
public:

	Sterling() :mPounds(0), mShilling(0),
		mPens(0){}
	Sterling(double funt)
	{
		// converting
		mPounds = static_cast<long>(funt);
		
		long deschast = funt - mPounds;
		
		mShilling = static_cast<int>(deschast * 20);
		mPens = static_cast<int>((funt - mPounds) * 240 
			- mShilling * 12);
	}
	Sterling(long pounds, int shilling, int pens) :
		mPounds(pounds), mShilling(shilling), mPens(pens){}

	void getSterling();
	void putSterling() const;

	Sterling operator +(Sterling sterling);
	Sterling operator -(Sterling sterling);

	Sterling operator *(double sterling);

	Sterling operator /(Sterling sterling);
	Sterling operator /(double sterling);

	operator double();
};