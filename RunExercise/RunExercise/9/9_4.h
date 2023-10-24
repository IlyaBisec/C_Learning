// Demonstration of the choice of the disk
// by the offspring of Disk class

#pragma once

#include "..\stdafx.h"

namespace NineFour {

	// classes conflict. because I added 'namespace' 
	// in this file

	class Publication
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
		static constexpr int COUNT_MONTH = 3;

	public:
		// total sum for last 3 months
		float totalSum[COUNT_MONTH];

		void getData();
		void putData() const;
	};


	class Book : protected Publication, private Sales
	{
	public:

		Book() :m_countPage(0) {}

		void getData();
		void putData() const;

	private:
		int m_countPage; // count of page

	};

	class Type : private Publication, private Sales
	{
	public:

		Type() :m_recordTime(0) {}

		void getData();
		void putData() const;
	private:
		float m_recordTime;	// recording time in minutes
	};

	class Disk :private Publication, private Sales
	{
	public:

		void getData();
		void putData() const;

	private:

		enum EDiskType
		{
			CD, DvD
		};
	};

}

