#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template <typename T>
void print_mas(T mas, int n)
{
	cout << mas[0];
	for (int i = 1; i < n; i++)
		cout << ' ' << mas[i];
	cout << '\n';
}

void FastSort(int* mas, int size)
{
	int i = 0;
	int j = size - 1;
	int pivot = mas[size / 2];
	do
	{
		while (mas[i] < pivot)
		{
			i++;
		}
		while (mas[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			swap(mas[i], mas[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
	{
		FastSort(mas, j + 1);
	}
	if (i < size)
	{
		FastSort(&mas[i], size - i);
	}
}


int main()
{
    srand(time(0));
    cout << "Размер массива: ";
    int temp_int;
    cin >> temp_int;
    int* mas = new int[temp_int];
    cout << "Исходный массив: ";
    for (int i = 0; i < temp_int; i++)
    {
        mas[i] = rand() % 100 - 50;
        cout << mas[i] << ' ';
    }
    cout << "\nОтсортированный массив: ";
    FastSort(mas, temp_int);
    print_mas(mas, temp_int);
    delete[] mas;
}