#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int *arr;
    int capacity;

public:
    Stack(int size)
    {
        arr = new int[size];
        top = -1;
        capacity = size;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int value)
    {

        if (top == capacity - 1)
        {

            cout << "Stack is overFlow " << endl;
        }
        else
        {
            top++;

            arr[top] = value;
        }
    }

    void pull()
    {
        if (top == -1)
        {
            cout << "Stack is underFlow " << endl;
        }
        else
        {
            top--; // if top is at 5 then at 4
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << " " << arr[i] << endl;
            }
        }
    }

    int peek()
    {
        if (top != -1)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
};

int main()
{
    Stack obj(5);

    obj.push(1);
    obj.push(2);
    obj.push(3);
    obj.push(4);
    obj.push(5);

    obj.display();

    obj.pull();
    obj.pull();

    obj.display();

    cout << "Top element is: " << obj.peek() << endl;

    return 0;
}

