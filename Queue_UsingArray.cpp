#include <iostream>
using namespace std;
class Queue
{
private:
    int size;
    int front;
    int rear;
    int *arr;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (rear == size) // Check full
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Enqueue(int value)
    {
        if (!isFull())
        {
            if (front == size - 1)
            {
                front = 0;
            }

            arr[rear] = value;
            rear++;
        }
    }

    int Dequeue()
    {
        int value = 0;
        if (!isEmpty())
        {
            if (rear == size - 1)
            {
                rear = 0;
            }
            value = arr[front];
            front++;
        }
        return value;
    }

    int peek()
    {
        return arr[front];
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << " " << arr[i];
        }
    }
};

int main()
{
    Queue obj(5);

    obj.Enqueue(5);
    obj.Enqueue(8);
    obj.Enqueue(6);
    obj.Enqueue(2);
    obj.Enqueue(3);

    obj.Dequeue();

    cout << " " << obj.peek() << endl;
    obj.display();
    return 0;
}
