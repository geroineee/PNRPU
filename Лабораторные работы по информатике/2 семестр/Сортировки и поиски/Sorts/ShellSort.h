#pragma once
#include <vector>
#include <iostream>
using namespace std;

void ShellSort(vector <int> vect)
{
	int j, tmp;
	bool flag;
	for (int step = int(vect.size()) / 2; step > 0; step /= 2)
	{
		flag = true;
		for (int i = step; i < int(vect.size()) / 2; i++)
		{
			tmp = vect[i];
			for (j = i; j >= step && flag; j -= step)
			{
				if (tmp < vect[j - step])
				{
					vect[j] = vect[j - step];
				}
				else
				{
					break;
				}
			}
			vect[j] = tmp;
		}
	}
}