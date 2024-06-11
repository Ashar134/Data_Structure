#include <iostream>
using namespace std;

class list
{
private:
    int *array;
    int *current;
    int length;
    int capacity;

public:
    list(int size)
    {
        array = new int[size];
        capacity = size;
        length = 0;
        current = NULL;
    }

    list(list &otherobj)
    {
        capacity = otherobj.capacity;
        length = otherobj.length;
        array = new int[capacity];

        for (int i = 0; i < length; i++)
        {
            array[i] = otherobj.array[i];
        }
    }
    void start() // At the start of list
    {
        current = array;
    }

    void next() // Bring current pointer to NEXT
    {
        current++;
    }

    void back() // Bring  Current pointer to back
    {
        current--;
    }

    void tail()
    {
        start();
        for (int i = 0; i < length - 1; i++)
        {
            next();
        }
    }

    void insert(int value, int position)
    {
        if (length == capacity)
        {
            cout << "List is Already is Full" << endl;
        }
        else
        {
            start();
            for (int i = 1; i < position; i++)
            {
                next();
            }
            *current = value;
            length++;
        }
    }

    void clear() // Making the array empty
    {
        length = 0;
    }

    void remove(int position) // remove the element at the position
    {

        current = array + position - 1;
        for (int i = position; i < length; i++)
        {
            *current = *(current + 1);
            next();
        }
        length--;
    }

    int *getElement(int position) // element at a given position
    {
        current = array + position - 1;

        return current;
    }

    void updateElement(int value, int position) // Updating element at the given position
    {
        if (position < 1 || position > length)
        {
            cout << "Error! Position is incorrect" << endl;
        }
        else
        {
            start();
            current = array + position - 1;
            *current = value;
        }
    }

    void findElement(int value) // Find the element in the list
    {
        start();
        bool found = false;

        for (int i = 0; i < length; i++)
        {
            if (*current == value)
            {
                found = true;
                break;
            }
            next(); // if not found moving the pointer to next
        }

        if (found)
        {
            cout << "Element " << *current << " is in the list" << endl;
        }
        else
        {
            cout << "Element " << value << " Not Found" << endl;
        }
    }

    int listLength() // Array list length
    {
        return length;
    }

    void reverseList()
    {
        tail();
        cout << "ReverseList :";
        for (int i = 0; i < length; i++)
        {
            cout << " " << *current;
            back();
        }
        cout << endl;
    }

    void sortList()
    {
        int temp = 0;

        for (int i = 0; i < length; i++)
        {
            start();
            for (int j = 0; j < length - 1; j++)
            {
                if (*current > *(current + 1))
                {
                    temp = *current;
                    *current = *(current + 1);
                    *(current + 1) = temp;
                }
                next();
            }
        }
    }

    void isFull()
    {
        if (capacity == length)
        {
            cout << "List is Full" << endl;
        }
        else
        {
            cout << "List is not yet Full" << endl;
        }
    }

    void isEmpty()
    {
        if (length == 0)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            cout << "List is not Empty,have Element in it" << endl;
        }
    }

    void displayList()
    {
        cout << "List :";
        for (int i = 0; i < length; i++)
        {
            cout << " " << array[i];
        }
        cout << endl;
    }

    ~list()
    {
        delete[] array;
    }
};

int main()
{
    int choice;
    list obj(5);

    obj.insert(10, 1); // Insertion
    obj.insert(20, 2);
    obj.insert(30, 3);
    obj.insert(3, 4);
    obj.insert(1, 5);
    obj.displayList();

    cout << "get : " << *obj.getElement(2) << endl;

    obj.updateElement(40, 2);
    obj.updateElement(50, 4);
    cout << "Array list atfer Update " << endl;
    obj.displayList();

    cout << "Finding Element" << endl;
    obj.findElement(40);
    obj.findElement(10);

    cout << "Array list length is :" << obj.listLength() << endl;

    obj.reverseList(); // reversing the list
    obj.sortList();    // Arranging the list to Ascending  order
    cout << "After Sorting the Array list" << endl;
    obj.displayList();

    list otherObj(obj);
    cout << "Copying the list" << endl;
    otherObj.displayList();

    do
    {
        cout << "Press 1| to clear list" << endl;
        cout << "Press 2| Is list empty" << endl;
        cout << "Press 3| Is list full" << endl;
        cout << "Press 4| Display list" << endl;
        cout << "Press 5|to Check copy list" << endl;
        cout << "Press 6| to Exist " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:

            obj.clear();
            cout << "List is clear" << endl;
            break;
        case 2:

            obj.isEmpty();
            break;
        case 3:
            obj.isFull();
            break;

        case 4:

            obj.displayList();
            break;
        case 5:
            otherObj.displayList();
            break;
        default:
            cout << "Exist the Program" << endl;
        }
    } while (choice != 6);

    return 0;
}