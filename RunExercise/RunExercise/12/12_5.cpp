// Representation of the time value

#include "pre12.h"

namespace chapter12_5{
	class Time
	{
	public:
		Time():m_hours(0), m_minutes(0), m_seconds(0){}

		void getTime();
		void putTime() const;

	private:
		int m_hours,    // h 0-23
			m_minutes,	// m 0-59
			m_seconds;  // s 0-59

		int getTime(int timeValue, int firstInterv, int secondInterv);
	};


	int Time::getTime(int timeValue, int firstInterv, int secondInterv)
	{
		while (true)
		{
			std::cout << "Enter watch time: ";
			std::cin.unsetf(std::ios::skipws); // Do not skip whitespace symbols
			std::cin >> timeValue;

			if (std::cin.good())
			{
				if (timeValue >= firstInterv && timeValue <= secondInterv)
				{
					// Removing unnecessary characters from the stream
					std::cin.ignore(80, '\n');
					break;
				} 
				else
				{
					std::cout << "Time interval between " << firstInterv << " and " << secondInterv << "!\n";
				}
			} 
			else
			{
				std::cin.clear();
				std::cout << "The time of the clock is entered incorrectly!\n";
			}
			std::cin.ignore(80, '\n');
		}
		return timeValue;
	}

	void Time::getTime()
	{
		m_hours   = getTime(m_hours,   0, 23);
		m_minutes = getTime(m_minutes, 0, 59);
		m_seconds = getTime(m_seconds, 0, 59);
	}

	void Time::putTime() const
	{
		std::cout << "Time: " <<
			((m_hours < 10) ? "0" : "") << m_hours << ":" <<
			((m_minutes < 10) ? "0" : "") << m_minutes << ":" <<
			((m_seconds < 10) ? "0" : "") << m_seconds;
	}
}


int main12_5()
{
	chapter12_5::Time time;
	char choice;

	do
	{
		time.getTime();
		time.putTime();

		std::cout << "\nContinue? y/n ";
		std::cin >> choice;
		std::cin.ignore(80, '\n');

	} while (choice == 'y');
	
	return 0;
}
