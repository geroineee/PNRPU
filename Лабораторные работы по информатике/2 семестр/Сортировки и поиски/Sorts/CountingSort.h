#pragma once
#include<vector>
#include<iostream>
using namespace std;

void CountingSort(vector<int>& vect)
{
	int max_element = vect[0];
	int min_element = vect[0];
	for (int i = 0; i < int(vect.size()); i++)
	{
		if (max_element < vect[i]) max_element = vect[i];
		else if (min_element > vect[i]) min_element = vect[i];
	}

	vector<int> temp(max_element - min_element + 1);
	for (int i = 0; i < int(vect.size()); i++)
	{
		temp[vect[i] - min_element]++;
	}

	for (int i = 0; i < max_element - min_element + 1; i++)
	{
		if (temp[i])
		{
			cout << i + min_element << "[" << temp[i] << "] ";
		}
	}
	cout << endl;

	int index = 0;
	for (int i = 0; i < max_element - min_element + 1; i++)
	{
		for (int step = 0; step < temp[i]; step++)
		{
			vect[index] = i + min_element;
			index++;
		}
	}
}