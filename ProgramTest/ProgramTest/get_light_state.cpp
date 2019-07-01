#include "oj.h"
#include <math.h>
#include <stdio.h>

bool GetLightState(int lightNum)
{
	int rootNum = (int)sqrt(lightNum);
	if (rootNum  * rootNum == lightNum)
	{
		return true;
	}
	else {
		return false;
	}
}

void TestGetLigthState()
{
	for (int i = 1; i <100000000; ++i)
	{
		if (GetLightState(i))
		{
			printf("%d\n", i);
		}
	}
}