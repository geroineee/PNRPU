#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include "Pair.h"
#include "P_queue.h"
using namespace std;

ostream &operator<<(ostream &, priority_queue<Pair, vector<Pair>, Pair_increase>);
Pair all_sum(priority_queue<Pair, vector<Pair>, Pair_increase>);

int main()
{
    srand(time(0));
    int q_size;
    cout << "Введите размер очереди: ";
    cin >> q_size;

    P_queue my_queue;
    my_queue.generate_Q(q_size);
    cout << my_queue;

    Pair sum = all_sum(my_queue);
    Pair average(sum.getFirst() / my_queue.size(), sum.getSecond() / my_queue.size());
    cout << "\nСреднее арифметическое: " << average << "\n\n";
    
    my_queue.push(sum);
    cout << "После добавления среднего арифметического:\n"
         << my_queue << "\n";

    Pair first_p, second_p;
    cout << "Введите две пары чисел, из диапазона которых будут удалены элементы списка:\n";
    cout << "Первая пара:\n";
    cin >> first_p;
    cout << "Вторая пара:\n";
    cin >> second_p;

    if (first_p > second_p)
    {
        swap(first_p, second_p);
    }
    my_queue.remove_from_range(first_p, second_p);
    cout << "\nПосле удаления из диапазона:\n"
         << my_queue << "\n";

    my_queue.substr_to_all(average);
    cout << "После вычитания среднего арифметического " << average << " :\n"
         << my_queue;

    cout << "Введите значение pair, по которому необходимо найти пару: ";
    Pair tmp_pair;
    cin >> tmp_pair;
    int index = my_queue.find_pair(tmp_pair);
    if (index)
        cout << "Элемент найден, его номер: " << index + 1 << "\n";
    else
        cout << "Элемент не найден.\n";
    return 0;
}

Pair all_sum(priority_queue<Pair, vector<Pair>, Pair_increase> temp_Q)
{
    Pair sum(0, 0);
    while (!temp_Q.empty())
    {
        Pair top_pair = temp_Q.top();
        sum = sum + top_pair;
        temp_Q.pop();
    }
    return sum;
}
