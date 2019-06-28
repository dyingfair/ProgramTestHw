#include "oj.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void SwapInt(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}


void MaxHeapify(int *arr, const int kLength, const int kIndex)
{
	//	assert(NULL != arr && 0 < kLength);
	int left = kIndex * 2;
	int rigth = kIndex * 2 + 1;
	int largest = kIndex;

	if (left < kLength && arr[left] < arr[largest])
		largest = left;

	if (rigth < kLength && arr[rigth] < arr[largest])
		largest = rigth;

	if (largest != kIndex) {
		SwapInt(&arr[kIndex], &arr[largest]);
		MaxHeapify(arr, kLength, largest);
	}
}

void BuileMaxHeap(int *arr, const int kLength)
{
	for (int i = kLength / 2; i >= 0; --i)
		MaxHeapify(arr, kLength, i);
}


void FindMaxKElem(int *arr_data, const int kLength, const int kNum)
{
	if (kLength <= 0 || arr_data == NULL || kNum <= 0) {
		return;
	}
	BuileMaxHeap(arr_data, kLength);
	int heap_size = kLength;

	for (int i = heap_size; i > kLength - kNum; --i) {
		printf("%d ", arr_data[0]);
		SwapInt(&arr_data[0], &arr_data[i - 1]);
		--heap_size;
		MaxHeapify(arr_data, heap_size, 0);
	}

	printf("\n");
}

const int nkLen = 30;
void TestHeapSort2(int nkNum)
{
	int *pAllData = new int[nkLen];
	
	srand((unsigned int)time(NULL));

	for (int i = 0; i < nkLen; ++i)
		pAllData[i] = rand() % 113;



	for (int i = 0; i < nkLen; ++i) {
		int nIndex1 = ( rand() * RAND_MAX + rand() ) % nkLen;
		int nIndex2 = ( rand() * RAND_MAX + rand() ) % nkLen;
		SwapInt(&pAllData[nIndex2], &pAllData[nIndex1]);
	}

	for (int i = 0; i < nkLen; ++i) {
		printf("%d ", pAllData[i]);
	}
	printf("\n");
	clock_t tStart = clock();
	FindMaxKElem(pAllData, nkLen, nkNum);
	clock_t tEnd = clock();
	printf("利用堆排序法寻找最大的10个数使用时间 : %lu\n", tEnd - tStart);

	delete[]pAllData;
}

void TestKminNumber()
{
	for (int i = 1; i < nkLen; ++i) {
		TestHeapSort2(i);

	}
}