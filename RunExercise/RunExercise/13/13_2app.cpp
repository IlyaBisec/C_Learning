#include "13_2.h"
using namespace ElevatorSystem;

int main13_2()
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