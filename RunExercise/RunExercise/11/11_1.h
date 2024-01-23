// A class of publications and its offspring

#pragma once

#include "..\stdafx.h"

namespace chapter_11 {

	class Publication {
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

	protected:
		char p_title[LENGTH];
		float p_price;
	};

	class Book : public Publication {
	public:
		void getData();
		void putData() const;

	private:
		int m_countPage; // count of page
	};

	class Type : public Book {
	public:
		void getData();
		void putData() const;

	private:
		float m_recordTime; // recording time in minutes
	};

}