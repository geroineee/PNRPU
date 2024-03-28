#pragma once
#include <vector>
#include <iostream>

#include "usefulFuncs.h"

using namespace std;

void sortShell(vector<int>& arr)
{
	int d = arr.size() / 2;
	while (d != 0) {
		for (int i = 0; i < arr.size() - d; ++i)
		{
			int sort = i;
			while (sort != 0 && arr[sort] > arr[sort + d])
			{
				int temp = arr[sort];
				arr[sort] = arr[sort + d];
				arr[sort + d] = temp;
				sort--;
			}
		}
		d = d / 2;
	}
}

void HoarSort(vector<int> &vect, int startIndex, int endIndex, bool visualization)
{
    int left, right, support_element, tmp;
    left = startIndex;
    right = endIndex;
    support_element = vect[(startIndex + endIndex) / 2];
    do
    {
        while ((vect[left] < support_element) && (left < endIndex))
            left++;
        while ((support_element < vect[right]) && (right > startIndex))
            right--;
        if (left <= right)
        {
            if (visualization) cout << vect[left] << " <-> " << vect[right] << endl; // визуализация
            tmp = vect[left];
            vect[left] = vect[right];
            vect[right] = tmp;
            left++;
            right--;
            if (visualization)
            {
                print(vect, vect.size());                             // визуализация
                cout << endl;                                         // визуализация
            }
        }
    } while (left <= right);
    if (startIndex < right)
        HoarSort(vect, startIndex, right, visualization);
    if (left < endIndex)
        HoarSort(vect, left, endIndex, visualization);
}

void HoarSort(vector<int> &vect, bool visual = true)
{
    HoarSort(vect, 0, vect.size() - 1, visual);
}