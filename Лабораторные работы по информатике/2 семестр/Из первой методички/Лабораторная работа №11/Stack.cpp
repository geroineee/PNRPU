#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next_ptr = nullptr;
};
struct Stack
{
    Node *head = nullptr, *tail = nullptr;
    int size = 0;

    void print()
    {
        Node *node = head;
        while (node != nullptr)
        {
            cout << node->data << ' ';
            node = node->next_ptr;
        }
    }

    void push(char data)
    {
        Node *node = new Node;
        node->data = data;
        if (head == nullptr)
            head = node;
        else if (tail != nullptr)
            tail->next_ptr = node;
        tail = node;
        size++;
    }

    void pop()
    {
        if (tail == nullptr)
            return;
        if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
            --size;
            return;
        }
        Node *node = head;
        for (; node->next_ptr != tail; node = node->next_ptr)
            ;
        node->next_ptr = nullptr;
        delete tail;
        tail = node;
        --size;
    }

    char top()
    {
        return tail->data;
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
    Stack stack;
    Stack stack2;

    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    char temp;
    for (int i = 0; i < n; ++i)
    {
        cout << "Введите " << i + 1 << "-ый элемент: ";
        cin >> temp;
        stack.push(temp);
    }

    do
    {
        cout << "Введите номер элемента, который необходимо удалить: ";
        cin >> temp;
    } while (int(temp) - int('0') - 1 < 0);
    int index = n - 1;
    while (index != int(temp) - int('0') - 1)
    {
        stack2.push(stack.top());
        stack.pop();
        index--;
    }
    stack.pop();
    n--;
    while (index != n)
    {
        stack.push(stack2.top());
        stack2.pop();
        index++;
    }
    stack.print();
    cout << endl;
    cout << "Введите сколько элементов добавить: ";
    cin >> temp;
    index = int(temp) - int('0') - 1;
    for (int i = 0; i < n; i++)
    {
        stack2.push(stack.top());
        stack.pop();
    }
    for (int i = 0; i <= index;i++)
    {
        cout << "Введите " << i+1 <<"-ый элемент: ";
        cin >> temp;
        stack.push(temp);
    }
    for (int i = 0; i < n; i++)
    {
        stack.push(stack2.top());
        stack2.pop();
    }
    stack.print();
    cout << endl;
    while (stack.size != 0)
    {
        stack.pop();
    }
}