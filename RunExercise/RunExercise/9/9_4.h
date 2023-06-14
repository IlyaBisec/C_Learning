// Demonstration of the choice of the disk
// by the offspring of Disk class

#pragma once

#include "..\stdafx.h"

namespace NineFour {

	const int LENGTH = 80;

	// classes conflict. because I added 'namespace' 
	// in this file

	class Publication
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


	class Book : protected Publication, private Sales
	{
	public:

		Book() :m_CountPage(0) {}

		void getData();
		void putData() const;

	private:
		int m_CountPage; // count of page

	};

	class Type : private Publication, private Sales
	{
	public:

		Type() :m_RecordTime(0) {}

		void getData();
		void putData() const;
	private:
		float m_RecordTime;	// recording time in minutes
	};

	class Disk :private Publication, private Sales
	{
	public:

		void getData();
		void putData() const;

	private:

		enum DiskType
		{
			k_CD, k_DvD
		};
	};

}

