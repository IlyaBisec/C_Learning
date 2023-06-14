#pragma once

#include "..\stdafx.h"

const int LENGTH = 80;

class Publication
{
public:
	void getData();
	void putData() const;

protected:
	char p_Tittle[LENGTH];
	float p_Price;	
};

class Book :public Publication
{
public:
	void getData();
	void putData() const;
private:
	int m_CountPage; // count of page

};

class Type : public Book
{
public:
	void getData();
	void putData() const;
private:
	float m_RecordTime;	// recording time in minutes
};

