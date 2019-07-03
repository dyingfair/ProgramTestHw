#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include "oj.h"
using namespace std;

bool isHuiwen(const string &str)
{
	if (str.length() == 0) {
		return false;
	}
	size_t len = str.length();
	size_t half_len = str.length() / 2;
	for (size_t i = 0; i < half_len; ++i) {
		if (str[i] != str[len - i - 1]) {
			return false;
		}
	}
	return true;
}


string GetMaxHuiwen(const string &inputStr)
{
	string huiwen;
	size_t len = inputStr.length();
	for (size_t i = 0; i < len; ++i) {
		for (size_t j = len; j > i; --j) {
			if (isHuiwen(inputStr.substr(i, j - i))) {
				if (huiwen.length() < j - i) {
					huiwen = inputStr.substr(i, j - i);
				}
			}
		}
	}
	return huiwen;
}

void TestGetMaxHuiwen(/*int argc, char **argv*/)
{
	cout << GetMaxHuiwen(string("a")) << endl;
	cout << GetMaxHuiwen(string("a1ba")) << endl;
	cout << GetMaxHuiwen(string("abab")) << endl;
	cout << GetMaxHuiwen(string("ababa")) << endl;
	cout << GetMaxHuiwen(string("aaba")) << endl;
	cout << GetMaxHuiwen(string("aadfba")) << endl;
	cout << GetMaxHuiwen(string("aadfadfewrfdffffffffffffffffffffbaaadfadfewrfdffffffffffffffffffffbaaadfadfewrfdffffffffffffffffffffbaaadfadfewrfdffffffffffffffffffffba")) << endl;
	cout << GetMaxHuiwen(string("afasdfdffffffffffffffffffffbaaadfadfewrfdffffffffffffffffffffffffffffffffffffffbaaadfadfewrfdffffffffffffffffffffbadffffffffffffffffffffbaaadfadfewrfdffffffffffffffffffffbaaadfadfewrfdffffffffffffffffffffbaaadfadfewrfdffffffffffffffffffffbadffffffffffffffffffffbaaadfadfewrfdffffffffffffffffffffbaaadfadfewrfdffffffffffffffffffffbaaadfadfewrfdffffffffffffffffffffbaadsfadfadfba")) << endl;

}