#include "8_5.h"


int main8_5()
{
	Time time;
	int sec = 59;

	time = sec;

	(++(++(++time)));
	time.displayTime();

	(--(--(--time)));
	time.displayTime();

	return 0;
}



long Time::convertTimeToSeconds() const
{
	return (m_hours * 3600 + m_minutes * 60 + m_seconds);
}

void Time::convertSecondsToTime(long inputSeconds)
{
	m_hours = inputSeconds / 3600;
	m_minutes = (inputSeconds % 3600) / 60;
	m_seconds = (inputSeconds % 3600) % 60;
}

// Adding two given times and storing the result
void Time::addTime(const Time &time1, const Time &time2)
{
	long total;

	total = time1.convertTimeToSeconds() + time2.convertTimeToSeconds();
	convertSecondsToTime(total);
}


// Unary operations
Time Time::operator+(const Time &time) const
{
	long total;

	total = convertTimeToSeconds() + time.convertTimeToSeconds();
	return Time(total);
}

// Postfix

Time Time::operator++(int)
{
	Time time;
	++(*this);
	return time;

}

Time Time::operator--(int)
{
	Time time;
	--(*this);
	return time;

}

// Prefix

Time &Time::operator++()
{
	++m_seconds;
	if (m_seconds >= 60)
	{
		m_seconds = 60;
		++m_minutes;

		if (m_minutes >= 60)
		{
			m_minutes = 60;
			++m_hours;
		}
	}

	return (*this);		
}

Time &Time::operator--()
{
	--m_hours;
	if (m_hours <= 0)
	{
		m_hours = 0;
		--m_minutes;
		if (m_minutes <= 0)
		{
			m_minutes = 0;
			--m_seconds;
		}
	}

	return (*this);
}
