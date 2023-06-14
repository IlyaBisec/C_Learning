// Multiple inheritance of the publication
// class
#pragma once

#include "..\stdafx.h"

const int LENGTH = 80;

// classes conflict. because I added 'New' 
// to classes

class NewPublication
{
public:
	void getData();
	void putData() const;

protected:
	char p_Title[LENGTH];
	float p_Price;
};

class Sales
{
private:
	static const int COUNT_MONTH = 3;

public:
	// total sum for last 3 months
	float totalSum[COUNT_MONTH];

	void getData();
	void putData() const;
};


class NewBook : private NewPublication, private Sales
{
public:

	NewBook():m_CountPage(0){}

	void getData();
	void putData() const;
private:
	int m_CountPage; // count of page

};

class NewType : private NewPublication, private Sales
{
public:

	NewType() :m_RecordTime(0) {}

	void getData();
	void putData() const;
private:
	float m_RecordTime;	// recording time in minutes
};


