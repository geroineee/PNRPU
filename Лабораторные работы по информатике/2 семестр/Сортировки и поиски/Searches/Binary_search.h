#pragma once
#include <iostream>
using namespace std;


int binary_search(int *mas, int &key, int size)
{
	int left = 0, right = size - 1, mid;
	while (left <= right)
	{
		mid = (right + left) / 2;
		if (mas[mid] == key)
		{
			return mid;
		}
		else
		{
			if (mas[mid] < key)
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return -1;
}
