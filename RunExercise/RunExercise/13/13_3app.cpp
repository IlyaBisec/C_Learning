#include "13_3.h"
using namespace ElevatorSystemMod;

int main13_3()
{
	Building buildig;

	while(true)
	{
		buildig.elevator_start();
		wait(1000);
		buildig.record_floorRequest();
	}
	return 0;
}