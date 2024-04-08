#include <iostream>
#include <string>
#include <clocale>
using namespace std;

struct Node
{
    char data;
    Node* next_ptr = nullptr;
};

struct List
{
    Node* head = nullptr;
    Node* tail = nullptr;

    void print()
    {
        cout << endl << "------------------------------" << endl;
        for (Node* node = head; node != nullptr; node = node->next_ptr)
            cout << node->data << ' ';
        cout << endl << "------------------------------" << endl;
    }
    void pop_front()
    {
        if (head == nullptr)
            return;
        if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* node = head;
        head = node->next_ptr;
        delete node;
    }
    void push_back(char data)
    {
        Node* node = new Node;
        node->data = data;
        if (head == nullptr)
            head = node;
        if (tail != nullptr)
            tail->next_ptr = node;
        tail = node;
    }
    void push_front(char data)
    {
        Node* node = new Node;
        node->data = data;
        node->next_ptr = head;
        head = node;
        if (tail == nullptr)
            tail = node;
    }
    void pop_back()
    {
        if (tail == nullptr)
            return;
        if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* node = head;
        for (; node->next_ptr != tail; node = node->next_ptr)
            ;
        node->next_ptr = nullptr;
        delete tail;
        tail = node;
    }
    Node* getPtr(int k)
    {
        if (k < 0)
            return 0;

        Node* node = head;
        int n = 0;
        while (node && n != k && node->next_ptr)
        {
            node = node->next_ptr;
            n++;
        }
        if (n == k)
            return node;
        else
            return nullptr;
    }
    void erase(int k)
    {
        if (k < 0)
            return;
        if (k == 0)
        {
            pop_front();
            return;
        }

        Node* left = getPtr(k - 1);
        Node* node = left->next_ptr;
        if (node == nullptr)
            return;

        Node* right = node->next_ptr;
        left->next_ptr = right;
        if (node == tail)
            tail = left;
        delete node;
    }

    void clear()
    {
        while (head != nullptr)
            pop_front();
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    int index = 0;
    List list;
    cout << "Введите количество элементов списка: ";
    cin >> n;
    char temp;
    for (int i = 0; i < n; ++i)
    {
        cout << "Введите " << i + 1 << " элемент: ";
        cin >> temp;
        list.push_back(temp);
    }
    list.print();

    cout << "Введите номер элемента, который хотите удалить: ";
    cin >> temp;
    index = 0;
    for (Node* node = list.head; node != nullptr; node = node->next_ptr)
    {
        if (index == int(temp)- int('0') - 1)
        {
            list.erase(index);
            break;
        }
        index++;
    }
    list.print();

    cout << "Количество элементов для добавления в начало списка: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Введите " << i + 1 << " элемент: ";
        cin >> temp;
        list.push_front(temp);
    }
    cout << endl;
    cout << "Результат: ";
    list.print();
    cout << endl;

    list.clear();
}
