#include <iostream>
#include <clocale>

using namespace std;

struct Node
{
    char data;
    Node *prev = nullptr, *next = nullptr;
};

struct LinkedList
{
    Node *head = nullptr, *tail = nullptr;
    void print()
    {
        cout << "------------------------------" << endl;
        for (Node *node = head; node != nullptr; node = node->next)
            cout << node->data << ' ';
        cout << endl
             << "------------------------------" << endl;
    }
    void push_head(char data)
    {
        Node *ptr = new Node;
        ptr->data = data;
        ptr->next = head;
        if (head != nullptr)
            head->prev = ptr;
        if (tail == nullptr)
            tail = ptr;
        head = ptr;
    }

    void push_tail(char data)
    {
        Node *ptr = new Node;
        ptr->data = data;

        ptr->prev = tail;
        if (tail != nullptr)
            tail->next = ptr;
        if (head == nullptr)
            head = ptr;
        tail = ptr;
    }

    void pop_front()
    {
        if (head == nullptr)
            return;

        Node *ptr = head->next;
        if (ptr != nullptr)
            ptr->prev = nullptr;
        else
            tail = nullptr;

        delete head;
        head = ptr;
    }

    void pop_back()
    {
        if (tail == nullptr)
            return;

        Node *ptr = tail->prev;
        if (ptr != nullptr)
            ptr->next = nullptr;
        else
            head = nullptr;

        delete tail;
        tail = ptr;
    }

    Node *getPtr(int index)
    {
        Node *ptr = head;
        int n = 0;
        while (n != index)
        {
            if (ptr == nullptr)
                return ptr;
            ptr = ptr->next;
            n++;
        }
        return ptr;
    }

    void erase(int index)
    {
        Node *ptr = getPtr(index);
        if (ptr == nullptr)
            return;

        if (ptr->prev == nullptr)
        {
            pop_front();
            return;
        }

        if (ptr->next == nullptr)
        {
            pop_back();
            return;
        }

        Node *left = ptr->prev;
        Node *right = ptr->next;
        left->next = right;
        right->prev = left;
        delete ptr;
    }
    void clear()
    {
        while (head != NULL)
            pop_front();
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    int index;
    LinkedList list;
    cout << "Введите количество элементов списка: ";
    cin >> n;
    char temp;
    for (int i = 0; i < n; ++i)
    {
        cout << "Введите " << i + 1 << "-ый элемент: ";
        cin >> temp;
        list.push_tail(temp);
    }
    list.print();
    cout << "Введите номер элемента, который хотите удалить: ";
    cin >> temp;
    index = 0;
    for (Node *node = list.head; node != nullptr; node = node->next)
    {
        if (index == int(temp) - int('0') - 1)
        {
            list.erase(index);
            break;
        }
        index++;
    }
    cout << endl;
    list.print();
    cout << "Введите сколько элементов необходимо добавить в начало списка: ";
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Введите элемент: ";
        cin >> temp;
        list.push_head(temp);
    }
    cout << "Итоговый список: " << endl;
    list.print();
    list.clear();
}
