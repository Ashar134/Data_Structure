#include <iostream>
using namespace std;
class Node
{
public:
    string song;
    Node *next;
    Node(string song)
    {
        this->song = song;
        next = NULL;
    }
};

class list
{
private:
    Node *head;
    int length;

public:
    list()
    {
        length = 0;
        head = NULL;
    }

    void insert(string value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *temp = head;

            while (temp->next != head)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            head = newNode;
            temp->next = head;
        }
        length++;
    }

    void remove()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty." << endl;
        }

        Node *temp = head;

        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        Node *lastNode = temp->next;
        temp->next = head;
        delete lastNode;

        length--;

        cout << "Song removed from the playlist." << endl;
    }

    void display()
    {
        Node *temp = head;
        do
        {
            cout << " " << temp->song << endl;
            temp = temp->next;
        } while (temp != head);
    }
};

int main()
{
    list obj;
    string songName;
    int choice;

    do
    {
        cout << "Press 1| Add Song" << endl;
        cout << "Press 2| Delete Song" << endl;
        cout << "Press 3| Display Song" << endl;
        cout << "Press 4| Exist" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the Song Name :";
            cin >> songName;
            obj.insert(songName);
            break;
        case 2:
            obj.remove();
            break;
        case 3:
            obj.display();
            break;
        default:
            cout << "Exist from the Program" << endl;
            break;
        }

    } while (choice != 4);
}