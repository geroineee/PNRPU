#include <list>
#include "pair.h"
#include "List.h"
#include <functional>


using namespace std;

int main()
{
    double sum1 = 0;
    double sum2 = 0;

    List my_list;
    int temp_int;
    Pair temp_pair;
    Pair temp_pair2;

    cout << "\nВведите количество эл-ов: ";
    cin >> temp_int;
    my_list.fill_list(temp_int);
    my_list.print();

    // находим среднее арифметическое среди элементов списка (по сумме первого и второго элемента каждой пары)
    for_each(my_list.begin(), my_list.end(), [&sum1, &sum2](Pair p)
             {sum1 += p.getFirst(); sum2 += p.getSecond(); });
    double average1 = sum1 / temp_int;
    double average2 = sum2 / temp_int;
    temp_pair.set(average1, average2);
    cout << "\nСредее арифметическое пар: " << temp_pair << endl;

    cout << "\nВведите позицию, куда необходимо вставить среднее арифметическое пар: ";
    cin >> temp_int;
    my_list.insert_pair(temp_int, temp_pair);
    my_list.print();

    cout << "\nВведите две пары чисел, из диапазона которых будут удалены все пары списка : ";
    cin >> temp_pair >> temp_pair2;
    if (temp_pair2 < temp_pair)
    {
        Pair temp = temp_pair2;
        temp_pair2 = temp_pair;
        temp_pair = temp;
    }
    auto s = remove_if(my_list.begin(), my_list.end(), [&temp_pair, &temp_pair2](Pair &p)
                       {if ((temp_pair <= p) && (p <= temp_pair2)) {return true;}return false; });
    my_list.erase(s, my_list.end());
    my_list.print();

    cout << "\nДобавление к каждому элементу среднего арифметического:\n";
    for_each(my_list.begin(), my_list.end(), [&average1, &average2](Pair &p)
             { p.set(p.getFirst() + average1,
                     p.getSecond() + average2); });
    my_list.print();

    cout << "\nСортировка по Убыванию:";
    my_list.sort([](Pair& a, Pair& b) {return a > b; });
    my_list.print();

    cout << "\nСортировка по Возрастанию:";
    my_list.sort([](Pair& a, Pair& b) {return a < b; });
    my_list.print();

    cout << "\nВведите значение, по которому необходимо найти пару: ";
    cin >> temp_pair;
    temp_int = 0;
    s = find_if(my_list.begin(), my_list.end(), [&temp_pair, &temp_int](Pair& p) {temp_int++;return temp_pair == p;});
    if (s != my_list.end())
    {
        cout << "Элемент найден, его номер: " << temp_int << endl;
    }
    else
        cout << "Элемент не найден." << endl;
}