#include <iostream>
#include <clocale>

using namespace std;
struct Node
{
    char data;
    Node* next_ptr = nullptr;
};
struct Queue
{

    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    void print()
    {
        Node* node = head;
        while (node != nullptr)
        {
            cout << node->data << ' ';
            node = node->next_ptr;
        }
        cout << endl;
    }

    void pop()
    {
        if (head == nullptr)
            return;
        if (head == tail)
        {
            delete tail;
            size--;
            head = tail = nullptr;
            return;
        }
        Node* node = head;
        head = head->next_ptr;
        delete node;
        size--;
    }
    void push(char data)
    {
        Node* node = new Node;
        node->data = data;
        if (head == nullptr)
            head = node;
        if (tail != nullptr)
            tail->next_ptr = node;
        tail = node;
        size++;
    }
    char front()
    {
        return head->data;
    }

    void clear()
    {
        while (head != nullptr)
            pop();
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Queue queue;
    cout << "Введите количество элементов: ";
    int temp_int;
    cin >> temp_int;
    char temp;
    for (int i = 0; i < temp_int; ++i)
    {
        cout << "Введите " << i + 1 << "-ый элемент: ";
        cin >> temp;
        queue.push(temp);
    }
    cout << "Введите номер элемента, который необходимо удалить: ";
    cin >> temp_int;
    temp_int--; // в индексы
    Queue queue2;
    int temp_size = queue.size;
    for (int i = 0; i < temp_size; i++)
    {
        if (i == temp_int)
        {
            queue.pop();
            continue;
        }
        queue2.push(queue.front());
        queue.pop();
    }
    for (int i = queue2.size; i > 0; i--)
    {
        queue.push(queue2.front());
        queue2.pop();
    }
    queue.print();
    cout << "Введите количество элементов для добавления в начало очереди: ";
    cin >> temp_int;
    for (int i = queue.size; i > 0; i--)
    {
        queue2.push(queue.front());
        queue.pop();
    }
    for (int i = 0; i < temp_int; i++)
    {
        cout << "Введите " << i + 1 << "-ый элемент: ";
        cin >> temp;
        queue.push(temp);
    }
    for (int i = queue2.size; i > 0; i--)
    {
        queue.push(queue2.front());
        queue2.pop();
    }
    cout << "Результат: " << endl;
    queue.print();
}