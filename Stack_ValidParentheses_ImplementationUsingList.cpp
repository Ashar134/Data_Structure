#include <iostream>
using namespace std;

class Node
{
public:
    char bracket;
    Node *prev;
    Node(char bracket)
    {
        this->bracket = bracket;
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

public:
    void push(char bracketType)
    {
        Node *newNode = new Node(bracketType);
        newNode->prev = top;
        top = newNode;
        length++;
    }

    char pop()
    {
        Node *current = top;
        char bracket;

        bracket = current->bracket;
        top = current->prev;

        delete current;
        length--;

        return bracket;
    }

    bool isValid(string str)
    {
        char openBracket;
        Stack obj;
        for (char bracket : str)
        {
            if (bracket == '(' || bracket == '[' || bracket == '{')
            {
                obj.push(bracket);
            }
            else
            {
                openBracket = obj.pop();
            }

            if ((openBracket != '(' && bracket == ')') ||
                (openBracket != '[' && bracket == ']') ||
                (openBracket != '{' && bracket == '}'))
            {

                return false;
            }
        }
        return true;
    }
};

int main()
{
    Stack obj;
    string bracket;
    int choice;

    do
    {
        cout << "Enter bracket :";
        cin >> bracket;

        if (obj.isValid(bracket))
        {
            cout << "Output : True" << endl;
        }
        else
        {
            cout << "Output : False" << endl;
        }
        cout << "Press 1 | To Continue" <<endl;
        cout << "Press 2 | To Exist " <<endl;
        cin >> choice;

    } while (choice != 2);

    cout << "Exit the Program" << endl;
    return 0;
}