#pragma once

// Adding the isOversize() method, which points to objects that have exceeded the allowed size

#include "../stdafx.h"

namespace chapter_11_4 {

	class Publication
	{
	public:
		virtual void getData()
		{
			std::cout << "Input title: ";
			std::cin.get(p_title, LENGTH);

			std::cout << "Input price: ";
			std::cin >> p_price;
		}
		virtual void putData() const
		{
			std::cout << "Title: " << p_title << "\n";
			std::cout << "Price: " << p_price << "\n";
		}

		virtual bool isOversize() const = 0;

	protected:
		char  p_title[LENGTH];
		float p_price;
	};

	class Book : public Publication
	{
	public:
		void getData();
		void putData() const;

		bool isOversize() const;

	private:
		int m_countPage; // count of page
	};

	class Type : public Publication
	{
	public:
		void getData();
		void putData() const;

		bool isOversize() const;

	private:
		float m_recordTime; // recording time in minutes
	};

}
