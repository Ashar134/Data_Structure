#include <iostream>
using namespace std;
// Double link list
class Node
{
public:
    int id;
    string name;
    int price;
    int quantity;
    Node *next;
    Node *prev;
    Node(int id, string name, int price, int quantity)
    {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        next = NULL;
        prev = NULL;
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

    void insert(int data, string name, int price, int quantity)
    {
        Node *newNode = new Node(data, name, price, quantity);

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

            if (newNode->id < temp->id)
            {
                if (head->next == NULL)
                {
                    head = newNode;
                }

                newNode->next = temp;
                temp->prev = newNode;
            }
            else
            {
                temp->next = newNode;
                newNode->prev = temp;
            }
        }
        length++;
    }

    void removeProduct(int id)
    {
        Node *temp = head;
        Node *slow = head;

        if (head == NULL)
        {
            cout << "No Product in the list" << endl;
        }
        else
        {

            while (temp->id != id)
            {
                slow = temp;
                temp = temp->next;
            }
            if (temp->id == head->id)
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
            cout << "Product Deleted" << endl;
            cout << "---------------" << endl;
        }
    }

    void updatePrice(int id)
    {
        int newPrice;
        Node *temp = head;
        for (int i = 0; i < length; i++)
        {
            if (temp->id == id)
            {
                cout << "Enter the Update Price :";
                cin >> newPrice;
                temp->price = newPrice;
                break;
            }
            temp = temp->next;
        }
    }

    void findProduct(int id)
    {
        Node *temp = head;
        bool found = false;
        for (int i = 0; i < length; i++)
        {
            if (temp->id == id)
            {
                cout << "-------Product-------" << endl;
                cout << "ID: " << temp->id << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Price: " << temp->price << endl;
                cout << "Quantity: " << temp->quantity << endl;
                cout << "----------------------" << endl;
                found = true;
                break;
            }

            temp = temp->next;
        }
        if (!found)
        {
            cout << "Product not found" << endl;
        }
    }

    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Quantity: " << temp->quantity << endl;
            cout << "----------------------" << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    list obj;
    int id;
    string name;
    int price;
    int quantity;
    int choice;
    
    do
    {

        cout << "Press 1| Add Product" << endl;
        cout << "Press 2| Update Product Price" << endl;
        cout << "Press 3| Find Product" << endl;
        cout << "Press 4| Delete Product" << endl;
        cout << "Press 5| Display Products" << endl;
        cout << "Press 6| Exist the Program" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "ID :";
            cin >> id;
            cout << "Product Name :";
            cin >> name;
            cout << "Price :";
            cin >> price;
            cout << "Quantity :";
            cin >> quantity;
            obj.insert(id, name, price, quantity);
            break;

        case 2:
            cout << "Enter ID :";
            cin >> id;
            obj.updatePrice(id);
            break;

        case 3:
            cout << "Enter ID to found :";
            cin >> id;
            obj.findProduct(id);
            break;

        case 4:
            cout << "Enter ID Product to Delete :";
            cin >> id;
            obj.removeProduct(id);
            break;

        case 5:
            cout << "---------PRODUCT LIST---------" << endl;
            obj.display();
            break;

        default:
            cout << "Exist the Program" << endl;
        }

    } while (choice != 6);

}