// oop_22.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <cstring>
bool isPalindrome(char str[], int i) 
{
	int p = (strlen(str) - i);
	if (i == 0) 
	{
		return true;
	}
	if (str[p] != str[i - 1])
	{
		return false;
	}
	return isPalindrome(str, i - 1);
}
int main()
{
	
	char str[10];
	gets_s(str);
	int i = strlen(str);
	cout << isPalindrome(str, i)<<endl;
    return 0;
}

