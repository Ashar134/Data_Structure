#include <iostream>
using namespace std;

class Hash
{
private:
    int size;
    int *arr;

public:
    Hash(int size)
    {
        this->size = size;
        arr = new int[size];

        for (int i = 0; i < size; ++i)
        {
            arr[i] = -1;
        }
    }

    int is70Percent()
    {
        int count = 0;

        for (int i = 0; i < size; i++)
        {
            if (arr[i] != -1)
            {
                count++;
            }
        }

        int capacity = (float(count) / size) * 100; // Cal the max capacity of table

        return capacity;
    }

    int hashFunc(int k)
    {
        return k % size;
    }

    void insert(int k)
    {

        if (k <= 0 || k > 100)
        {
            cout << "Range is between 1 - 100 " << endl;
        }
        else
        {

            int index = hashFunc(k);
            int capacity = is70Percent();

            if (capacity >= 70)
            {
                cout << "Capacity is Full...Double the size of Table " << endl;

                int prevSize = size;
                int newSize = 2 * size;
                setSize(newSize);

                // cout << "New size of Table : " << getSize() << endl; // Size of new Table
                // cout << "Old size of Table : " << prevSize << endl;

                int *newArr = new int[newSize];

                for (int i = 0; i < newSize; i++) // Assigning default values
                {
                    newArr[i] = -1;
                }

                for (int i = 0; i < prevSize; i++)
                {
                    if (arr[i] != -1) // Taking the value from old table
                    {
                        int newIndex = hashFunc(arr[i]);

                        while (newArr[newIndex] != -1)
                        {
                            newIndex = (newIndex + 1) % newSize;
                        }
                        newArr[newIndex] = arr[i];
                    }
                }

                delete[] arr; // deleting the memory of old table
                arr = newArr; // Assigning the new array to arr
            }

            while (arr[index] != -1)
            {
                index = (index + 1) % size;
            }
            arr[index] = k;
        }
    }

    int search(int k)
    {
        int index = hashFunc(k);

        while (arr[index] != -1)
        {
            if (arr[index] == k)
            {
                return index;
            }
            index = (index + 1) % size;
        }

        return -1;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "At index " << i << " " << arr[i] << endl;
        }
    }

    void setSize(int size)
    {
        this->size = size;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    Hash obj(10);
    int value;
    int choice;
    int capacity;
    int searchValue;
    int index;
    char check = 'y';

    // obj.insert(7);
    // obj.insert(12);
    // obj.insert(11);
    // obj.insert(15);
    // obj.insert(65);
    // obj.insert(14);
    // obj.insert(66);
    // obj.insert(18);
    // obj.insert(99);

    do
    {
        cout << "Press 1 | To Insert " << endl;
        cout << "Press 2 | To Search " << endl;
        cout << "Press 3 | To Display Table " << endl;
        cout << "Press 4 | To Exist " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:

            if (capacity < 70)
            {
                do
                {
                    cout << "Enter the value : ";
                    cin >> value;
                    obj.insert(value);
                    capacity = obj.is70Percent();
                    cout << "Continue :";
                    cin >> check;

                } while (check == 'y');

                // obj.display();
            }

            // cout << "size of old Table : " << obj.getSize() << endl;
            cout << "--------------------------" << endl;
            break;

        case 2:
            cout << "--------Searching...--------" << endl;

            cout << "Enter the Value to Search " << endl;
            cin >> searchValue;
            index = obj.search(searchValue);

            if (index != -1)
            {
                cout << " " << searchValue << " found at index: " << index << endl;
            }
            else
            {
                cout << " " << searchValue << " not found." << endl;
            }

            break;

        case 3:

            cout << "--------Displaying...--------" << endl;
            obj.display(); // Displaying the table

            cout << "-----------------------------" << endl;

            break;

        default:

            cout << "Exist the Program " << endl;
        }

    } while (choice != 4);

    return 0;
}
