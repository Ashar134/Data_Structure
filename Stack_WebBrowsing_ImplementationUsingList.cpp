#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node *prev;
    Node(string name)
    {
        this->name = name;
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
    void push(string name)
    {
        Node *newNode = new Node(name);
        newNode->prev = top;
        top = newNode;
        length++;
    }

    string pull()
    {
        Node *current = top;
        string value;
        if (length == 0)
        {
            return "";
        }
        else
        {
            value = current->name;
            top = current->prev;

            delete current;
            length--;
        }
        return value; // If we need the value later or we can reverse it by doing this
    }

    string peek()
    {
        if (length == 0)
        {
            cout << "No more Page" << endl;
            return "";
        }
        else
        {
            return top->name;
        }

        return "";
    }

    void Checklength() // check length
    {
        cout << "Length :" << length << endl;
    }

};

int main()
{
    Stack obj;
    int choice;
    string name;
    Stack back;
    Stack forward;
    do
    {

        cout << "Press 1 | Go on Website" << endl;
        cout << "Press 2 | Back " << endl;
        cout << "Press 3 | Forward " << endl;
        cout << "Press 4 | Exist " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Website: ";
            cin >> name;
            back.push(name);
            break;
            
        case 2:
            if (!back.peek().empty())
            {
                cout << "Currently on Website: " << back.peek() << endl;
                name = back.pull();
                forward.push(name);
                cout << "Clicked Back Button, Now on Website: " << back.peek() << endl;
            }
            else
            {
                cout << "No more pages to go back" << endl;
            }
            break;

        case 3:
            if (!forward.peek().empty())
            {
                name = forward.pull();
                back.push(name);
                cout << "Clicked Forward Button, Now on Website: " << back.peek() << endl;
            }
            else
            {
                cout << "No more pages to go forward" << endl;
            }
            break;

        default:
            cout << "Exiting the program" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
