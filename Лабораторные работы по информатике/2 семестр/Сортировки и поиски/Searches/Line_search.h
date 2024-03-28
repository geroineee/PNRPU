#pragma once
#include <iostream>
using namespace std;



int Line_search(int *mas, int &key, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (mas[i] == key)
		{
			return i;
		}
	}
	return -1;
}