#include "common.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void NumToChar(unsigned int array_int[], unsigned int len, char *str_int) {

	int start_id = len - 1;

	while (start_id >= 0 && 0 == array_int[start_id])
	{
		--start_id;
	}
	if (0 > start_id)
	{
		str_int[0] = '0';
		return;
	}

	for (unsigned int i = 0; i <= start_id; ++i)
	{
		str_int[i] = array_int[start_id - i] + '0';
	}

}
static void CharToIntArray(const char *str_int, unsigned int array_int[]) {

	unsigned int length = strlen(str_int);
	for (unsigned int i = 0; i < length; i++)
	{
		array_int[i] = str_int[length - 1 - i] - '0';
	}
}


static void MultiDo(unsigned int *num1_array, unsigned int *num2_array, unsigned int *sum_array, unsigned int len1, unsigned int len2)
{

	for (unsigned int i = 0; i < len1; i++)
	{
		for (unsigned int j = 0; j < len2; j++)
		{
			sum_array[i + j] += num1_array[i] * num2_array[j];
		}
	}

	unsigned int id = len1 + len2;
	for (unsigned int i = len1 + len2 - 1; i >= 0; --i)
	{
		if (sum_array[i] == 0)
		{
			--id;
		}
		else {
			break;
		}
	}

	int c = 0;

	for (unsigned int i = 0; i <= id; ++i)
	{
		sum_array[i] += c;
		c = sum_array[i] / 10;
		sum_array[i] = sum_array[i] % 10;
	}

	if (c != 0)
	{
		sum_array[id + 1] = c;
	}
}

static char * Multi(const char *num1, const char *num2) {
	if (num1 == NULL || num2 == NULL)
	{
		return NULL;
	}
	unsigned int len1 = strlen(num1);
	unsigned int len2 = strlen(num2);
	unsigned int *num1_array = (unsigned int *)malloc(sizeof(unsigned int) * len1);
	unsigned int *num2_array = (unsigned int *)malloc(sizeof(unsigned int) * len2);
	unsigned int *sum_array = (unsigned int *)malloc(sizeof(unsigned int) * (len1 + len2));

	char *str_sum = (char *)malloc(len1 + len2 + 1);
	memset(str_sum, 0, len1 + len2 + 1);

	memset(sum_array, 0, sizeof(unsigned int) * (len1 + len2));
	CharToIntArray(num1, num1_array);
	CharToIntArray(num2, num2_array);

	MultiDo(num1_array, num2_array, sum_array, len1, len2);
	NumToChar(sum_array, len1 + len2, str_sum);

	free(num1_array);
	free(num2_array);
	return str_sum;
}

void test1() {
	const char *number1 = "789654123130416354668710306804610365";
	const char *number2 = "123167435208945873046534";
	const char *assert_sum = "97259673048142523048875426292669000319004693556619383724910";
	char *sum = Multi(number1, number2);

	printf(" num1: %s\n num2: %s\n sum: %s\n\n", number1, number2, sum);
	if (strcmp(sum, assert_sum)) {
		printf("assert sum %s\n real   sum %s\n\n", assert_sum, sum);
	}
	free(sum);
}

void test2() {
	const char *number1 = "789654123130416354668710306804610365";
	const char *number2 = "0";
	char assert_sum[] = "0";
	char *sum = Multi(number1, number2);

	printf(" num1: %s\n num2: %s\n sum: %s\n\n", number1, number2, sum);
	if (strcmp(sum, assert_sum)) {
		printf("assert sum %s\n real   sum %s\n\n", assert_sum, sum);
	}
	free(sum);
}

void test3() {
	const char *number1 = "111";
	const char *number2 = "1111";
	char assert_sum[] = "123321";
	char *sum = Multi(number1, number2);

	printf(" num1: %s\n num2: %s\n sum: %s\n\n", number1, number2, sum);
	if (strcmp(sum, assert_sum)) {
		printf("assert sum %s\n real   sum %s\n\n", assert_sum, sum);
	}
	free(sum);
}

void test4() {
	const char *number1 = "0";
	const char *number2 = "0";
	char assert_sum[] = "0";
	char *sum = Multi(number1, number2);

	printf(" num1: %s\n num2: %s\n sum: %s\n\n", number1, number2, sum);
	if (strcmp(sum, assert_sum)) {
		printf("assert sum %s\n real   sum %s\n\n", assert_sum, sum);
	}
	free(sum);
}

void test5() {
	const char *number1 = "6745645235422435234523450064616819694008161064569632584616";
	const char *number2 = "9632584580603134061380404845136745645235422435234523450064616819694008161064569632584616";
	char assert_sum[] = "64977998280949147833590979285463894425504911188544493397721553704037903281166200083807744164296331455584736637858893450167291554464304304399867456";
	char *sum = Multi(number1, number2);

	printf(" num1: %s\n num2: %s\n sum: %s\n\n", number1, number2, sum);
	if (strcmp(sum, assert_sum)) {
		printf("assert sum %s\n real   sum %s\n\n", assert_sum, sum);
	}
	free(sum);
}

void MultiTest() {
	test1();
	test2();
	test3();
	test4();
	test5();
}