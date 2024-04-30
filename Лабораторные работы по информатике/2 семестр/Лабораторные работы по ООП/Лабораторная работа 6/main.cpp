#include <iostream>
#include <vector>

#include "list.h"
#include "list.cpp"

#include "iterator.h"
#include "iterator.cpp"

using namespace std;

int main()
{
     List list;
     for (int i = 0; i < 5; ++i) // заполнение списка
          list.push_back(rand() % 100);

     list.print();
     cout << "Вывод второго элемента списка list[2]: ";
     cout << list[2] << endl;
     cout << "Расширение размера массива до 10 и увеличение элементов массива на 100 : " << endl;
     list(10);
     list += 100;

     list.print();
}