#include <iostream>
#include <vector>

#include "List.h"
#include "List.cpp"
#include "iterator.cpp"
#include "iterator.h"


using namespace std;

int main()
{
    cout << "Введите размер списка: ";
    try
    {
        int temp_int;
        cin >> temp_int;

        List list(temp_int);

        for (Iterator iterator(list); iterator.getNode() != nullptr; iterator++) // вывод
        {
            cin >> temp_int;
            iterator.getNode()->data = temp_int;
        }
        list.print();
        cout << "Первый элемент списка: ";
        cout << list[0] << endl;
        cout << "Ошибочные операции:\n";
        cout << list[-3] << endl;
        // cout << list[60] << endl;
        // cout << list[list.size] << endl;
    }
    catch (int)
    {
        cout << "Размер должен быть неотрицательным!";
    }
    catch (char)
    {
        cout << "Максимальный размер - 30!";
    }
    catch (float)
    {
        cout << "Индекс должен быть неотрицательным!";
    }
    catch (double)
    {
        cout << "Индекс должен быть в пределах размера списка!";
    }
}
