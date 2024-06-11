#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *prev;
    Node(int value)
    {
        this->info = value;
        prev = NULL;
    }
};

class Stack
{
private:
    Node *top;
    int length;

public:
    Stack()
    {
        top = NULL;
        length = 0;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->prev = top;
        top = newNode;
        length++;
    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        Node *current = top;
        int value = current->info;
        top = current->prev;
        delete current;
        length--;
        return value;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return top->info;
    }

    void display()
    {
        Node *current = top;
        cout << "Stack: ";
        while (current != NULL)
        {
            cout << current->info << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void postfix(char val)
    {

        if (val == '+' || val == '-' || val == '*' || val == '/')
        {
            int oprand1 = pop();
            int oprand2 = pop();
            int result = 0;
            switch (val)
            {
            case '+':
                result = oprand1 + oprand2;
                break;
            case '-':
                result = oprand2 - oprand1;
                break;
            case '*':
                result = oprand1 * oprand2;
                break;
            case '/':
                if (oprand1 < oprand2)
                {
                    int temp = 0;
                    temp = oprand1;
                    oprand1 = oprand2;
                    oprand2 = temp;
                }

                result = oprand1 / oprand2;

                break;
            }
            push(result);
        }
        else
        {
            int number = val - '0';
            push(number);
        }
    }
};

int main()
{
    Stack obj;

    obj.postfix('6');
    obj.postfix('8');
    obj.postfix('2');
    obj.postfix('/');
    obj.postfix('9');
    obj.postfix('+');
    
    obj.display();
    cout << "Peek: " << obj.peek() << endl;
    return 0;
}
