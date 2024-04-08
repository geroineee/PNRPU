#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void print_mas(T mas, int lenght_mas)
{
    cout << mas[0];
    for (int i = 1; i < lenght_mas; i++)
        cout << ' ' << mas[i];
    cout << '\n';
}

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

using namespace std;

pair<int, int> ideal_series(pair<int, int> last_count_series, int count_all_series)
{
    int current_num = last_count_series.first + last_count_series.second;
    if (count_all_series > current_num)
    {
        ideal_series({ last_count_series.second, current_num }, count_all_series);
    }
    else
    {
        return last_count_series;
    }
}

void series_merge(vector<vector<int>>& series_1, vector<vector<int>>& series_2, vector<vector<int>>& series_3)
{
    if (series_1.size() == 1 && series_2.size() == 0 && series_3.size() == 0)
        return;
    else if (series_2.size() == 1 && series_1.size() == 0 && series_3.size() == 0)
        return;
    else if (series_3.size() == 1 && series_1.size() == 0 && series_2.size() == 0)
        return;
    int index_1 = series_1.size() - 1;
    int index_2 = series_2.size() - 1;
    while (index_2 != -1) // пока series_2 не пуста
    {
        natural_merge(series_1[index_1], series_2[index_2]);
        series_3.push_back(series_1[index_1]);
        series_1.pop_back();
        series_2.pop_back();
        index_1--;
        index_2--;
    }
    series_merge(series_3, series_1, series_2); // 1-ый, там, где больше серий, 2-ой, там где меньше серий (потом пустой), 3-ий, куда сливаются
}

void multiphase_merge_sort(int* mas, int lenght_mas)
{
    pair<int, int> ideal_pair;
    vector<int> new_series;
    vector<vector<int>> series, series_1, series_2, series_3;
    for (int i = 0; i <= lenght_mas - 1; i++)
    {
        if (i == lenght_mas - 1)
        {
            new_series.push_back(mas[i]);
            series.push_back(new_series);
            new_series.clear();
        }
        else
        {
            new_series.push_back(mas[i]);
            if (mas[i] > mas[i + 1])
            {
                series.push_back(new_series);
                new_series.clear();
            }
        }
    }
    ideal_pair = ideal_series({ 0, 1 }, series.size());
    for (int i = 0; i < ideal_pair.second; i++)
    {
        series_1.push_back(series[i]);
    }
    for (int i = 0; i < ideal_pair.first; i++)
    {
        if (series_1.size() + i + 1 > series.size())
        {
            series_2.push_back({});
        }
        else
        {
            series_2.push_back(series[series_1.size() + i]);
        }
    }
    series_merge(series_1, series_2, series_3);
    for (int i = 0; i < lenght_mas; i++)
    {
        mas[i] = series_1[0][i];
    }
}

int main()
{
    system("chcp 1251 > null");
    cout << "Введите кол-во эл-ов массива: ";
    int temp_int;
    cin >> temp_int;
    int* mas = new int[temp_int];
    for (int i = 0; i < temp_int; i++)
    {
        cout << i + 1 << " элемент: ";
        cin >> mas[i];
    }
    multiphase_merge_sort(mas, temp_int);
    cout << "Отсортированный массив: ";
    print_mas(mas, temp_int);
}