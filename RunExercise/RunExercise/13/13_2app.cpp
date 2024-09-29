#include "13_2.h"


int main()
{
	Building building;

	while(true)
	{
		building.elevator_start();
		wait(1000);
		building.record_floorRequest();
	}

	return 0;
}