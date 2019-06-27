#include "oj.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
using namespace std;

void StackPush(char **stackChar, char c)
{
	( *stackChar )++;
	**stackChar = c;
}

char StackPop(char **stackChar)
{
	char tmp = **stackChar;
	( *stackChar )--;
	return tmp;
}

char StackTop(char *stackChar) 
{
	return *stackChar;
}

int StackEmpty(char *stackChar, char *stackHead)
{
	return (stackChar + 1)  == stackHead;
}

int PossibleOutQueue(int count, char *outQueue)
{
	char *stackArray = (char*)malloc(count + 1);
	char *stackTmp = stackArray - 1;
	int len = strlen(outQueue);
	
	int i = 0;
	int j = 0;
	int flag = 0;
	while(i < count)
	{
		if (StackEmpty(stackTmp, stackArray))
		{
			StackPush(&stackTmp, i + '1');
			i++;
		}
		else {
			if (StackTop(stackTmp) == outQueue[j]) {
				j++;
				StackPop(&stackTmp);
			}
			else {
				StackPush(&stackTmp, i + '1');
				i++;
			}
		}
	}
	while (j < count)
	{
		if (StackTop(stackTmp) == outQueue[j]) {
			StackPop(&stackTmp);
		}
		j++;
	}
	if (StackEmpty(stackTmp, stackArray)) {
		flag = 1;
	}
	free(stackArray);
	stackArray = NULL;
	return flag;

}

void TestPossibleOutQueue() {

	char myints[] = "123456789";
	int len = strlen(myints);
	std::sort(myints, myints + len);

	do {
		
		if(PossibleOutQueue(strlen(myints), myints)) {
			printf("%s: %d\n", myints, PossibleOutQueue(strlen(myints), myints));
		}
	} while (std::next_permutation(myints, myints + len));

}