#include "oj.h"
#include <stdio.h>
#include <stdlib.h>


int Min(int number1, int number2, int number3) {
	int minNum = number1;

	if (minNum > number2)
	{
		minNum = number2;
	}

	if (minNum > number3) {
		minNum = number3;
	}

	return minNum;
}

int FindUglyNumer(int index)
{
	if (index <= 0)
		return 0;

	int *uglyArray = (int *)malloc(index * sizeof(int));
	int nextUglyId = 1;

	uglyArray[0] = 1;
	int *multiFactor2 = uglyArray;
	int *multiFactor3 = uglyArray;
	int *multiFactor5 = uglyArray;

	while (nextUglyId < index) {
		int min = Min(*multiFactor2 * 2, *multiFactor3 * 3, *multiFactor5 * 5);
		uglyArray[nextUglyId] = min;

		while (*multiFactor2 * 2 <= uglyArray[nextUglyId])
			++multiFactor2;
		while (*multiFactor3 * 3 <= uglyArray[nextUglyId])
			++multiFactor3;
		while (*multiFactor5 * 5 <= uglyArray[nextUglyId])
			++multiFactor5;

		++nextUglyId;
	}

	int uglyOutput = uglyArray[nextUglyId - 1];
	free(uglyArray);
	uglyArray = NULL;
	return uglyOutput;
}


void TestFindUglyNumber() {
	int i = 0;

	for (i  =0; i <= 1500; ++i)
	{
		printf("%d:  %d\n", i, FindUglyNumer(i));
	}
}
