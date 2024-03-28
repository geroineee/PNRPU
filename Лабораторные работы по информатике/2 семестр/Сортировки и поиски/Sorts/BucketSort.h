#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "HoarSort.h"


void BucketSort(vector<int> &vect)
{
	int maxValue = vect[0];
	int minValue = vect[0];
	for (int i = 0; i < int(vect.size()); ++i)
	{
		if (maxValue < vect[i])
			maxValue = vect[i];
		else if (minValue > vect[i])
			minValue = vect[i];
	}
	int bucketsCount = maxValue / 10 - minValue / 10 + 1; // вычисление количества корзин
	vector<int> *buckets = new vector<int>[bucketsCount];

	for (int i = 0; i < int(vect.size()); i++)
	{
		buckets[vect[i] / 10 - minValue / 10].push_back(vect[i]); // заполнение корзин
	}
	
	for (int i = 0; i < bucketsCount; i++)
	{
		sortShell(buckets[i]); // сортировка каждой корзины
	}

	int index = 0; // индекс главного массива
	for (int i = 0; i < bucketsCount; i++) // заполнение главного массива
	{ 
		for (int j = 0; j < int(buckets[i].size()); j++)
		{
			vect[index++] = buckets[i][j];
		}
	}

	delete[] buckets; // очистка памяти
}