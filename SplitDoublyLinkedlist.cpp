#include <iostream>
using namespace std;
class Node      //Node Class
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class List
{
private:
    Node *head;
    int length;
    Node *oddHead;

public:
    List()
    {
        head = NULL;
        oddHead = NULL;
        length = 0;
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        length++;
    }

    void splitList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data % 2 != 0)   //If data is odd , assign to new doubly list
            {
                Node *oddlist = new Node(temp->data);
                if (oddHead == NULL)
                {
                    oddHead = oddlist;
                }
                else
                {
                    Node *temp = oddHead;

                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = oddlist;
                    oddlist->prev = temp;

                    removeOdd(temp->data); // Remove the odd Number from the list
                }
            }

            temp = temp->next;
        }
    }
    void removeOdd(int data)
    {
        Node *temp = head;
        Node *slow = head;

        while (temp->data != data)
        {
            slow = temp;
            temp = temp->next;
        }

        if (temp->data == head->data)
        {
            head = head->next;
            delete temp;
        }
        else
        {

            slow->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = slow;
            }
            delete temp;
        }
        length--;
    }

    void display()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            cout << " " << temp->data;
            temp = temp->next;
        }
    }
    void oddDisplay()
    {
        Node *temp = oddHead;
        while (temp != NULL)
        {
            cout << " " << temp->data;
            temp = temp->next;
        }
    }
};

int main()
{
    List obj;

    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);
    obj.insert(6);
    obj.insert(7);
    obj.insert(8);
    obj.insert(9);

    obj.display();
    cout<<endl;
    obj.splitList();
    cout<<"Odd :";
    obj.oddDisplay();
    cout<<endl;
    cout<<"Even :";
    obj.display();

    return 0;
}
