#include <iostream>
#include <clocale>
#include <vector>

#include "MergeSort.h"
#include "CountingSort.h"
#include "HoarSort.h"
#include "BucketSort.h"
#include "ShellSort.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(0));
	vector<int> arr;
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	int temp_int;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите: " << i + 1 << "-ый элемент: ";
		cin >> temp_int;
		arr.push_back(temp_int);
	}
	cout << "Исходный массив: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
	BucketSort(arr);
	cout << "Отсортированный массив: ";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ' ';
}
