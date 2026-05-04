#include "cl_1.h"

int ATM::summa(int fir, int sec)
{

	second = sec;
	for (int i = 0; i < 9; i++)
	{
		if (first[i] == fir) { return first[i] * second; }
	}
	return -1;
}