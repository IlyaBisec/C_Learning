// применение accumulate() с трем€ аргументами

#include "header.h"


namespace STL_15_7 {

	//  ласс по отслеживанию времени вылета и прилета самолетов
	class AirTime
	{
	public:
		AirTime(): m_hours(0), m_minutes(0)
		{ }
		AirTime(int hours, int minutes): m_hours(hours), m_minutes(minutes)
		{ }

		void display() const
			{ std::cout<<m_hours<<':'<<m_minutes; }
		void getTime()
		{
			char colon;
			std::cout << "\nEnter the time in the format(12:59): ";
			std::cin >> m_hours >> colon >> m_minutes;
		}

		AirTime operator+ (const AirTime &right) const;

		bool operator== (const AirTime &airtime) const;
		bool operator< (const AirTime &airtime) const;
		bool operator!= (const AirTime &airtime) const;
		bool operator> (const AirTime &airtime) const;

	private:
		int m_hours;
		int m_minutes;
	};

	AirTime AirTime::operator+(const AirTime &right) const
	{
		// —ложение полей
		int tempH = m_hours + right.m_hours;
		int tempM = m_minutes + right.m_minutes;

		// ѕроверка на перенос
		if (tempM >= 60)
		{
			tempH++;
			tempM -= 60;
		}

		return AirTime(tempH, tempM);
	}

	bool AirTime::operator==(const AirTime &airtime) const
	{
		return (m_hours == airtime.m_hours) && (m_minutes == airtime.m_minutes);
	}

	bool AirTime::operator<(const AirTime &airtime) const
	{
		return (m_hours < airtime.m_hours) || (m_hours == airtime.m_hours < airtime.m_minutes);
	}

	bool AirTime::operator!=(const AirTime &airtime) const
	{
		return !(*this == airtime);
	}

	bool AirTime::operator>(const AirTime &airtime) const
	{
		return !(*this < airtime) && !(*this == airtime);
	}

}

using namespace STL_15_7;


int main15_7()
{
	char answer;
	AirTime enterTime, sum;
	std::list<AirTime> airList;

	// Get time from user
	do
	{
		enterTime.getTime();
		airList.push_back(enterTime);
		std::cout << "Continue? (y/n) ";
		std::cin >> answer;

	} while (answer != 'n');

	// Calculate sum
	sum = std::accumulate(airList.begin(), airList.end(), AirTime(0, 0));

	std::cout << "\nSum: ";
	sum.display();

	std::cout << "\n";

	return 0;
}