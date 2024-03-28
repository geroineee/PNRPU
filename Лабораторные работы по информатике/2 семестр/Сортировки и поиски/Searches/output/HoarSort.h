#pragma once
#include <iostream>
using namespace std;


void ShellSort(int *mas, int size)
{
	int j, tmp, step;
	for (int i = 2; i < size / 2; i++)
	{
		if (size % i == 0)
		{
			step = i;
		}
	}
	for (step; step > 0; step /= 2)
	{
		for (int i = step; i < size; i++)
		{
			tmp = mas[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < mas[j - step])
				{
					mas[j] = mas[j - step];
				}
				else
				{
					break;
				}
			}
			mas[j] = tmp;
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << mas[i] << ' ';
	}
	cout << endl;
}
