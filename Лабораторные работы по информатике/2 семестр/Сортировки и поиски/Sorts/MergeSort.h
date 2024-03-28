#pragma once
#include <iostream>
#include <vector>
using namespace std;

void MergeSort(vector<int>& vect, int startIndex, int endIndex);

void MergeSort(vector<int>& vect)
{
	MergeSort(vect, 0, vect.size());
}

void Merge(vector<int>& vect, int startIndex, int endIndex)
{
	vector<int> temp;
	int start_first_part = startIndex;
	int end_first_part = (startIndex + endIndex) / 2;
	int start_second_part = end_first_part;
	
	while (int(temp.size()) < endIndex - startIndex)
	{
		if (start_first_part >= end_first_part
			|| (start_second_part < endIndex
				&& vect[start_second_part] <= vect[start_first_part]))
		{
			temp.push_back(vect[start_second_part]);
			start_second_part++;
		}
		else
		{
			temp.push_back(vect[start_first_part]);
			start_first_part++;
		}
	}
	for (int i = startIndex; i < endIndex; ++i)
		vect[i] = temp[i - startIndex];
}

void MergeSort(vector<int>& vect, int startIndex, int endIndex)
{
	if ((endIndex - startIndex) < 2)
		{
			cout << "sorted return: "<< vect[startIndex] << endl;
			return;
		}
	if ((endIndex - startIndex) == 2)
	{
		if (vect[startIndex] > vect[startIndex + 1])
		{
			swap(vect[startIndex], vect[startIndex + 1]);
			cout << "sorted return: "<< vect[startIndex] << ' ' << vect[startIndex + 1] << endl;
			return;
		}
	}

	cout << vect[startIndex];
	for (int i = startIndex+1; i < (startIndex + endIndex) / 2; i++)
	{
		cout << ' ' << vect[i];
	}
	cout << " <-> ";
	cout << vect[(startIndex + endIndex) / 2];
	for (int i = (startIndex + endIndex) / 2+1; i < endIndex; i++)
	{
		cout << ' ' << vect[i];
	}
	cout << endl;

	MergeSort(vect, startIndex, (startIndex + endIndex) / 2);
	MergeSort(vect, (startIndex + endIndex) / 2, endIndex);
	Merge(vect, startIndex, endIndex);
}
