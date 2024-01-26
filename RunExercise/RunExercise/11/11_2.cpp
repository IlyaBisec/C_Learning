#include "11_2.h"

using namespace chapter_11;

int main11_2()
{
	Distance dis1 = 2.5;
	Distance dis2 = 1.25;

	float dist_temp;

	std::cout << "dist1= "; dis1.showDist(); std::cout << std::endl;
	std::cout << "dist2= "; dis2.showDist(); std::cout << std::endl;

	dist_temp = dis1 * dis2;
	std::cout << std::endl;
	std::cout << "dist1 * dist2 = " << dist_temp << "feets \n";
	dist_temp =  dis2 * dis1;
	std::cout << "dist2 * dist1 = " << dist_temp << "feets \n";
	std::cout << std::endl;

	dist_temp = 7.5 * dis1;
	std::cout << "7.5 * dist1 = " << dist_temp << "feets \n";
	std::cout << std::endl;

	dist_temp = dis1 *7.5;
	std::cout << "dist1 * 7.5 = " << dist_temp << "feets \n";
	std::cout << std::endl;

	return 0;

}

