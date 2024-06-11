#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
    }
    Node(int data)
    {
        next = NULL;
        this->data = data;
    }
};

class Queue
{
private:
    Node *front;
    int length;

public:
    Queue()
    {
        length = 0;
        front = NULL;
    }

    void Enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (front == NULL)
        {
            front = newNode;
        }
        else
        {
            Node *rear = front;

            while (rear->next != NULL)
            {

                rear = rear->next;
            }

            rear->next = newNode;
        }
        length++;
    }

    void duplicateQueue(Queue &obj)
    {
        Node *front = obj.front;

        while (front != NULL)
        {
            int value = front->data;

            for (int i = 0; i < value; i++)
            {
                Enqueue(value);
            }
            front = front->next;
        }
    }
    
    void display()
    {
        Node *current = front;

        while (current != NULL)
        {
            cout << " " << current->data;
            current = current->next;
        }
    }

    int peek()
    {
        return front->data;
    }
};

int main()
{
    Queue obj, otherObject;
    int value;
    char choice;

    do
    {
        cout << "Enter Number :";
        cin >> value;
        obj.Enqueue(value);
        cout << "Want to enter another number y/n :";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Input :";
    obj.display();
    cout << endl;

    otherObject.duplicateQueue(obj);
    cout << "After Duplication :";
    otherObject.display();

    return 0;
}
