#include <iostream>
using namespace std;

class Node
{
public:
    string order;
    int price;
    Node *next;

    Node(string name = "N/A", int price = 0)
    {
        next = NULL;
        order = name;
        this->price = price;
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

    void Enqueue(string orderName, int price)
    {
        Node *newNode = new Node(orderName, price);

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

    Node *Dequeue()
    {
        int value;
        Node *temp = NULL;
        if (front == NULL)
        {
            cout << "Queue is UnderFlow" << endl;
        }
        else
        {
            Node *current = front;
            front = front->next;
            temp = current;
            delete current;
        }
        length--;

        return temp;
    }

    Node *peek()
    {
        return front;
    }
};

int main()
{
    Queue obj;
    int choice;
    int customerChoice;
    int cafeteriaChoice;
    char choose;
    Node *oldOrder;
    Node *nextOrder;
    Node *currentOrder;
    Node *cancelOrder;

    do
    {

        cout << "Press 1 | For Customer " << endl;
        cout << "Press 2 | For Cafeteria " << endl;
        cout << "Press 3 | To Exit" << endl;
        cin >> choice;

        if (choice == 1)
        {
            do
            {

                cout << "--------PLACE ORDER--------" << endl;
                cout << "Press 1 | Burger       | Rs 500" << endl;
                cout << "Press 2 | Pizze        | Rs 900" << endl;
                cout << "Press 3 | ClubSandwich | Rs 400" << endl;
                cout << "Press 4 | Wrap         | Rs 300" << endl;
                cout << "----------DRINKS-------------" << endl;
                cout << "Press 5 | Pepsi        | Rs 90" << endl;
                cout << "Press 6 | 7up          | Rs 90" << endl;
                cin >> customerChoice;

                switch (customerChoice)
                {
                case 1:
                    obj.Enqueue("Burger", 500);
                    break;

                case 2:
                    obj.Enqueue("Pizza", 900);
                    break;

                case 3:
                    obj.Enqueue("ClubSandwich", 400);
                    break;

                case 4:
                    obj.Enqueue("Wrap", 300);
                    break;

                case 5:
                    obj.Enqueue("Pepsi", 90);
                    break;

                case 6:
                    obj.Enqueue("7up", 90);
                    break;

                default:
                    cout << "Thanks For Ordering" << endl;
                    break;
                }

                cout << "Do you want to Continue y/n :";
                cin >> choose;

            } while (choose == 'y' || choose == 'Y');

            cout << "Thanks for Ordering" << endl;
        }
        else if (choice == 2)
        {
            do
            {
                cout << "Press 1 | To Check Order Processed" << endl;
                cout << "Press 2 | To Check Current Order" << endl;
                cout << "Press 3 | To Exit" << endl;
                cin >> cafeteriaChoice;

                switch (cafeteriaChoice)
                {
                case 1:
                    if (obj.peek() != NULL)
                    {
                        oldOrder = obj.peek(); // Checking the order that Processed
                        cout << "----Ordered Complete----" << endl;
                        cout << "Order Name :" << oldOrder->order << endl;
                        cout << "Price :" << oldOrder->price << endl;
                        cout << "-----------------------" << endl;
                        obj.Dequeue(); // Removing the order that complete

                        if (obj.peek() != NULL)
                        {
                            nextOrder = obj.peek(); // Then the Next order display
                            cout << "-----Next Ordered-----" << endl;
                            cout << "Order Name :" << nextOrder->order << endl;
                            cout << "Price :" << nextOrder->price << endl;
                            cout << "-----------------------" << endl;
                        }
                        else
                        {
                            cout << "No more Next Order" << endl;
                        }
                    }
                    else
                    {
                        cout << "No more Orders" << endl;
                    }
                    break;

                case 2:

                    currentOrder = obj.peek();
                    cout << "----Current Order Status----" << endl;
                    cout << "Order Name :" << currentOrder->order << endl;
                    cout << "Price :" << currentOrder->price << endl;
                    cout << "-----------------------" << endl;
                    break;

                default:
                    cout << "Thanks for using the System" << endl;
                }
            } while (cafeteriaChoice != 3); // Cafeteria Menu
        }

    } while (choice != 3); // Main menu

    cout << "Thanks for using the System" << endl;
    return 0;
}
