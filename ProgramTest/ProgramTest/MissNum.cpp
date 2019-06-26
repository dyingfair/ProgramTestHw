#include "oj.h"
#include <stdio.h>

long int MissNum(long int num)
{
	int minus = 0;
	int array1[10] = {0};
	long int result = 0;
	int tmp;

	if (num < 0) {
		minus = 1;
		num = -num;
	}
	if (num == 0) {
		return 0;
	}

	while (num) {
		tmp = num % 10;
		array1[tmp]++;
		if (array1[tmp] == 1) {
			result = result * 10 + tmp;
		}
		num /= 10;
	}
	if (minus) {
		result = -result;
	}
	return result;
}

void TestMissNum()
{
	long int input = 1;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = -222;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = 0;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = 1234567890;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = 11111;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = -1231241423;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = -901231543;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = -100091231;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = -1923423400;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = -1122330043;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = 1999;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = 99991;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = 741748585;
	printf("input %ld  output %ld\n", input, MissNum(input));

	input = 987654321;
	printf("input %ld  output %ld\n", input, MissNum(input));
}