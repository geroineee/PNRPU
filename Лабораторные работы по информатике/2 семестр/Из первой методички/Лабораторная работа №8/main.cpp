#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;
int j = 0; // индекс фильма

struct Film
{
    string title;     // название
    string director;  // режиссер
    int release_year; // год выпуска
    int cost;         // стоимость

    void add_film()
    {
        cout << "Данные для " << j + 1 << "-го фильма:" << endl;
        cout << "Название фильма: "; cin.seekg(cin.eof()); string title; getline(cin, title);
        cout << "Режиссер фильма: "; cin.seekg(cin.eof()); string director; getline(cin, director);
        cout << "Год выпуска фильма: "; int release_year; cin >> release_year;
        int cost;
        do
        {
            cout << "Стоимость билета на фильм: "; cin >> cost;
        }
        while(cost < 0);
        j++;
    }
};

void print_to_file(Film* arr, int n)
{
    ofstream file("output_films");
    file << "-------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        file << "Данные для " << i + 1 << "-го фильма:" << endl;
        file << "\tНазвание фильма: "; file << arr[i].title << endl;
        file << "\tРежиссер фильма: "; file << arr[i].director << endl;
        file << "\tГод выпуска фильма: "; file << arr[i].release_year << endl;
        file << "\tСтоимость билета на фильм: "; file << arr[i].cost << endl;
        file << "-------------------------------------------------" << endl;
    }
    file.close();
}

void print(Film* arr, int n)
{
    system("cls");
    cout << "-------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Данные для " << i + 1 << "-го фильма:" << endl;
        cout << "\tНазвание фильма: "; cout << arr[i].title << endl;
        cout << "\tРежиссер фильма: "; cout << arr[i].director << endl;
        cout << "\tГод выпуска фильма: "; cout << arr[i].release_year << endl;
        cout << "\tСтоимость билета на фильм: "; cout << arr[i].cost << endl;
        cout << "-------------------------------------------------" << endl;
    }
}


void del_film(Film* arr, int index, int n)
{
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    Film films[50];
    int amount; // количество фильмов в массиве
    cout << "Введите количество фильмов: ";
    cin >> amount;
    for (int i = 0; i < amount; i++)
    {
        films[i].add_film();
    }
    cout << "Введите свой бюджет: ";
    int money; cin >> money;
    for (int i = 0; i < amount; i++)
        if (films[i].cost > money)
        {
            del_film(films, i, amount);
            amount--;
        }
    print(films, amount);
    system("cls");
    for (int i = amount - 1; i >= 0; i--)
    {
        films[i + 1] = films[i];
    }
    films[0].add_film();
    amount++;
    print(films, amount);
    print_to_file(films, amount);
}