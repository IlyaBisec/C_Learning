// Multiple inheritance of the publication
// class
#pragma once

#include "..\stdafx.h"

// classes conflict. because I added 'New' 
// to classes

class NewPublication
{
public:
	void getData();
	void putData() const;

protected:
	char p_title[LENGTH];
	float p_price;
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

	NewBook():m_countPage(0){}

	void getData();
	void putData() const;
private:
	int m_countPage; // count of page

};

class NewType : private NewPublication, private Sales
{
public:

	NewType() :m_recordTime(0) {}

	void getData();
	void putData() const;
private:
	float m_recordTime;	// recording time in minutes
};


