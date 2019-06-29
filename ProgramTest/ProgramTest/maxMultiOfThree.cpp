#include "oj.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
using namespace std;

int maxMultiOfThree(vector<int> DataArr)
{
	if (DataArr.size() < 3) {
		return 0;
	}
	int MaxThree[3] = {INT_MIN, INT_MIN, INT_MIN};
	int MinTwo[2] = {INT_MAX, INT_MAX};
	int ProductMax1;
	int ProductMax2;
	for (size_t i = 0; i != DataArr.size(); ++i) {
		if (DataArr[i] >= MaxThree[0]) {
			MaxThree[2] = MaxThree[1];
			MaxThree[1] = MaxThree[0];
			MaxThree[0] = DataArr[i];
		}
		else if (DataArr[i] >= MaxThree[1]) {
			MaxThree[2] = MaxThree[1];
			MaxThree[1] = DataArr[i];
		}
		else if (DataArr[i] >= MaxThree[2]) {
			MaxThree[2] = DataArr[i];
		}

		if (DataArr[i] < MinTwo[0]) {
			MinTwo[1] = MinTwo[0];
			MinTwo[0] = DataArr[i];
		}
		else if (DataArr[i] < MinTwo[1]) {
			MinTwo[1] = DataArr[i];
		}
	}
	ProductMax1 = MaxThree[2] * MaxThree[1] * MaxThree[0];
	ProductMax2 = MinTwo[0] * MinTwo[1] * MaxThree[0];
	if (ProductMax1 >= ProductMax2) {
		return ProductMax1;
	}
	else {
		return ProductMax2;
	}
}

static void SwapInt(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void TestMaxMultiOfThreeDo(int length)
{
	int *pAllData = new int[length];

	srand((unsigned int)time(NULL));

	for (int i = 0; i < length; ++i)
		pAllData[i] = rand() % 100 - 50;

	for (int i = 0; i < length; ++i) {
		int nIndex1 = ( rand() * RAND_MAX + rand() ) % length;
		int nIndex2 = ( rand() * RAND_MAX + rand() ) % length;
		SwapInt(&pAllData[nIndex2], &pAllData[nIndex1]);
	}

	cout << "Input: ";
	for (int i = 0; i < length; ++i) {
		printf("%d ", pAllData[i]);
	}
	cout << endl;

	vector<int> inputData;
	for (int i = 0; i < length; ++i) {
		inputData.push_back(pAllData[i]);
	}
	cout << "MaxProduct: " << maxMultiOfThree(inputData) << endl;;
	delete[]pAllData;

}

void TestMaxMultiOfThree()
{
	int length = 50;
	for (int i = 1; i < length; ++i) {
		TestMaxMultiOfThreeDo(i);
		this_thread::sleep_for(chrono::seconds(1));
	}

}