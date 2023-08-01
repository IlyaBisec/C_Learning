#include "10_5.h"

int main10_5()
{
	float arr_alpha[5] = {1.0, 2.222, 3.1, 4.13, 5.02},
		  arr_beta[5] = { 10.0, 32.2, 13.10, 24.1, 15.2 },
		  arr_gamma[5];

	addArrays(arr_alpha, arr_beta, arr_gamma, 5);

	return 0;
}

void addArrays(float *ptr_alpha, float *ptr_betta, float *ptr_gamma, int arr_size)
{
	for (int i = 0; i < arr_size; i++) {
		*(ptr_gamma + i) = *(ptr_alpha + i) + *(ptr_betta + i);
		cout << *(ptr_gamma + i) <<((i != arr_size - 1) ? ", " : "");
	}
}