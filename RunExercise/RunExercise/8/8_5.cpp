#include "8_5.h"


int main()
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
	return (m_Hours * 3600 + m_Minutes * 60 + m_Seconds);
}

void Time::convertSecondsToTime(long inputSeconds)
{
	m_Hours = inputSeconds / 3600;
	m_Minutes = (inputSeconds % 3600) / 60;
	m_Seconds = (inputSeconds % 3600) % 60;
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
	++m_Seconds;
	if (m_Seconds >= 60)
	{
		m_Seconds = 60;
		++m_Minutes;

		if (m_Minutes >= 60)
		{
			m_Minutes = 60;
			++m_Hours;
		}
	}

	return (*this);		
}

Time &Time::operator--()
{
	--m_Hours;
	if (m_Hours <= 0)
	{
		m_Hours = 0;
		--m_Minutes;
		if (m_Minutes <= 0)
		{
			m_Minutes = 0;
			--m_Seconds;
		}
	}

	return (*this);
}
