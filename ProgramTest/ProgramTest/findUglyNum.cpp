#include "oj.h"
#include <stdio.h>
#include <stdlib.h>


int FindUglyNumber(int N)
{
	if (N <= 0)
		return 0;

	int *uglyArray = (int *)malloc(N * sizeof(int));
	int nextUglyId = 1;

	uglyArray[0] = 1;
	int *multiFactor2 = NULL;
	int *multiFactor3 = NULL;
	int *multiFactor5 = NULL;
	multiFactor2 = uglyArray;
	multiFactor3 = uglyArray;
	multiFactor5 = uglyArray;

	while (nextUglyId < N) {
		int tmp = *multiFactor2 * 2;
		uglyArray[nextUglyId] = tmp;
		tmp = *multiFactor3 * 3;
		
		if (uglyArray[nextUglyId] > tmp) {
			uglyArray[nextUglyId] = tmp;
		}

		tmp = *multiFactor5 * 5;
		if (uglyArray[nextUglyId] > tmp) {
			uglyArray[nextUglyId] = tmp;
		}

		while (*multiFactor2 * 2 <= uglyArray[nextUglyId]) {
			multiFactor2++;
		}
			
		while (*multiFactor3 * 3 <= uglyArray[nextUglyId]) {
			multiFactor3++;
		}

		while (*multiFactor5 * 5 <= uglyArray[nextUglyId]) {
			multiFactor5++;
		}
		++nextUglyId;
	}

	int uglyOutput = uglyArray[N - 1];
	free(uglyArray);
	uglyArray = NULL;
	return uglyOutput;
}


void TestFindUglyNumber()
{
	int i = 0;

	for (i = 0; i <= 1500; ++i) {
		printf("%d:  %d\n", i, FindUglyNumber(i));
	}
}
