#include "8_3.h"


int main8_3()
{
	Time timeFirst(1, 5, 1), timeSecond(2, 4, 5);
	Time timeSum;

	timeSum = timeFirst + timeSecond;
	
	timeFirst.displayTime();
	timeSecond.displayTime();
	timeSum.displayTime(); // 3 9 6

	return 0;
}


Time Time::operator+(const Time &time)
{
	long totalSeconds = (mHours*3600)+(mMinutes*60)+
		mSeconds+(time.mHours * 3600) + (time.mMinutes * 60) +time.mSeconds;

	int hours = totalSeconds / (60 * 60);
	int minutes = totalSeconds % (60 * 60) / 60;
	int seconds = totalSeconds % (60 * 60) % 60;

	return Time(hours, minutes, seconds);
}
