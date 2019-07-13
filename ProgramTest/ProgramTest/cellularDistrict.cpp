#include <stdlib.h>
#include "oj.h"

#include<stdio.h>
#include <time.h>


struct Position {
	int x;
	int y;
	int z;
};

static Position GetPosition(int val)
{
	int i = 0;
	int v = 1;
	Position pos;

	if (val == 1) {
		pos.x = 0;
		pos.y = 0;
		pos.z = 0;
		return pos;
	}
	// find the ring (i) that val belongs to.
	while (v < val) {
		++i;
		v += 6 * i;
	}
	int side = ( v - val ) / i;
	int offset = ( v - val ) % i;
	switch (side) {
	case 0:
		pos.x = i;
		pos.y = -i + offset;
		pos.z = pos.x + pos.y;
		break;
	case 1:
		pos.z = i;
		pos.y = offset;
		pos.x = pos.z - pos.y;
		break;
	case 2:
		pos.y = i;
		pos.z = i - offset;
		pos.x = pos.z - pos.y;
		break;
	case 3:
		pos.x = -i;
		pos.y = i - offset;
		pos.z = pos.x + pos.y;
		break;
	case 4:
		pos.z = -i;
		pos.y = -offset;
		pos.x = pos.z - pos.y;
		break;
	case 5:
		pos.y = -i;
		pos.z = -i + offset;
		pos.x = pos.z - pos.y;
		break;
	default:
		break;
	}
	return pos;
}

static int g_maxValue = 0;
int InitCellularDistrict(int iMaxSeqValue)
{
	if (iMaxSeqValue > 0 && iMaxSeqValue <= 100000) {
		g_maxValue = iMaxSeqValue;
		return 0;
	}
	return -1;
}

int GetShortestPathLength(int iFirstValue, int iSecondValue)
{
	if (iFirstValue < 0 || iFirstValue > g_maxValue)
	{
		return -1;
	}
	if (iSecondValue < 0 || iSecondValue > g_maxValue) {
		return -1;
	}

	Position pos1 = GetPosition(iFirstValue);
	Position pos2 = GetPosition(iSecondValue);
	int i = pos1.x > pos2.x ? pos1.x - pos2.x : pos2.x - pos1.x;
	int j = pos1.y > pos2.y ? pos1.y - pos2.y : pos2.y - pos1.y;
	int k = pos1.z > pos2.z ? pos1.z - pos2.z : pos2.z - pos1.z;

	int dis = (i > j) ? i: j ;
	dis = ( dis > k ) ? dis  : k ;
	return dis;

}

void Clear()
{
	g_maxValue = 0;
}


void TestGetShortestPathLength()
{
	int maxVal = 70;
	InitCellularDistrict(maxVal);

	srand(time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		int val1 = rand() * 1971 % maxVal + 1;
		int val2 = rand() * 1971 % maxVal + 1;
		Position pos1 = GetPosition(val1);
		Position pos2 = GetPosition(val2);
		printf("pos1: %d %d %d\n", pos1.x, pos1.y, pos1.z);
		printf("pos2: %d %d %d\n", pos2.x, pos2.y, pos2.z);
		printf("val1 %d  val2 %d  dis %d\n\n", val1, val2, GetShortestPathLength(val1,val2));
	}

	{
		int val1 = 1;
		int val2 = 70;
		Position pos1 = GetPosition(val1);
		Position pos2 = GetPosition(val2);
		printf("pos1: %d %d %d\n", pos1.x, pos1.y, pos1.z);
		printf("pos2: %d %d %d\n", pos2.x, pos2.y, pos2.z);
		printf("val1 %d  val2 %d  dis %d\n\n", val1, val2, GetShortestPathLength(val1, val2));
	}

	{
		int val1 = 2;
		int val2 = 1;
		Position pos1 = GetPosition(val1);
		Position pos2 = GetPosition(val2);
		printf("pos1: %d %d %d\n", pos1.x, pos1.y, pos1.z);
		printf("pos2: %d %d %d\n", pos2.x, pos2.y, pos2.z);
		printf("val1 %d  val2 %d  dis %d\n\n", val1, val2, GetShortestPathLength(val1, val2));
	}

	{
		int val1 = 70;
		int val2 = 61;
		Position pos1 = GetPosition(val1);
		Position pos2 = GetPosition(val2);
		printf("pos1: %d %d %d\n", pos1.x, pos1.y, pos1.z);
		printf("pos2: %d %d %d\n", pos2.x, pos2.y, pos2.z);
		printf("val1 %d  val2 %d  dis %d\n\n", val1, val2, GetShortestPathLength(val1, val2));
	}
	Clear();
}