#pragma once

#include "..\stdafx.h"

const int LENGTH = 80;

class Publication
{
protected:
	char mTittle[LENGTH];
	float price;	
public:
	void getData();
	void putData();
};

class Book :public Publication
{
private:
	int mCountPage; // count of page

public:
	void getData();
	void putData();
};

class Type : public Book
{
private:
	float mRecordTime;	// recording time in minutes
public:
	void getData();
	void putData();
};

