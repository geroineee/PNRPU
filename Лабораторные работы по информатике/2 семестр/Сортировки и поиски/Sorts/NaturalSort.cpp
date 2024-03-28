#include <iostream>
#include <vector>
using namespace std;

void natural_merge(vector<int>& vect1, vector<int>& vect2)
{
    for (int i = 0; i < vect2.size(); i++)
    {
        vect1.push_back(vect2[i]);
        for (int j = vect1.size() - 1; j > 0; j--)
        {
            if (vect1[j] < vect1[j - 1])
            {
                swap(vect1[j], vect1[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}

void natural_merge_sort(vector <int>& vect)
{
    int size = vect.size();
    vector <vector<int>> series;
    vector<int> new_series;
    for (int i = 0; i <= size - 1; i++)
    {
        if (i == size - 1)
        {
            new_series.push_back(vect[i]);
            series.push_back(new_series);
            new_series.clear();
            continue;
        }
        new_series.push_back(vect[i]);
        if (vect[i] <= vect[i + 1])
        {
            continue;
        }
        else
        {
            series.push_back(new_series);
            new_series.clear();
        }
    }
    while (series.size() != 1)
    {
        natural_merge(series[0], series[series.size() - 1]);
        series.pop_back();
    }
    vect = series[0];
}


int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(0));
    cout << "Введите размер массива: ";
    int lenght_mas;
    cin >> lenght_mas;
    vector<int> vect;
    for (int i = 0; i < lenght_mas; i++)
    {
        vect.push_back(rand() % 101);
        cout << vect[i] << ' ';
    }
    cout << endl;

    natural_merge_sort(vect);
    cout << vect[0];
    for (int i = 1; i < vect.size(); i++)
    {
        cout << ' ' << vect[i];
    }
    return 0;
}
