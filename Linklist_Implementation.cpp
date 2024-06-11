#include <iostream>
using namespace std;

class Node
{
public:
    int id;
    string name;
    double cgpa;
    Node *next;

    Node() // Constructor
    {
        id = 0;
        name = "N/A";
        cgpa = 0.0;
        next = NULL;
    }
    Node(int id, string name, float cgpa)
    {
        this->id = id;
        this->name = name;
        this->cgpa = cgpa;
        next = NULL;
    }
    
};

class StudentRecord
{
private:
    int studentId;
    string studentName;
    float cGpa;

public:
    StudentRecord()
    {
        studentId = 0;
        studentName = "N/A";
        cGpa = 0.0;
    }

    StudentRecord(int id, string name, float cgpa)
    {
        studentId = id;
        studentName = name;
        cGpa = cgpa;
    }

    void setId(int id)
    {
        studentId = id;
    }
    void setName(string name)
    {
        studentName = name;
    }
    void setCgpa(int gpa)
    {
        cGpa = gpa;
    }
    int setId()
    {
        return studentId;
    }
    string setName()
    {
        return studentName;
    }
    float setCgpa()
    {
        return cGpa;
    }

   
};

class ManageList
{
private:
    Node *head;
    int length;
    StudentRecord obj;   
public:
    ManageList()
    {
        head = NULL;
        length = 0;
    }
     ManageList(int id, string name, float cgpa) : obj(id,name,cgpa)
    {
        head = NULL;
        length = 0;
    }
  
    void addStudent(int id, string name, float cgpa) 
    {
        Node *newNode = new Node(id, name, cgpa);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }

        length++;
    }

    void removeStudent(int id)
    {

        Node *current = head;

        if (current->id == id)
        {
            head = current->next;
            delete current;
        }
        else
        {
            Node *previous = head;

            for (int i = 0; i < length - 1; i++)
            {
                if (current->id == id)
                {
                    previous->next = current->next;
                    delete current;
                    break;
                }
                else
                {
                    previous = current;
                    current = current->next;
                }
            }
            // delete current;
        }
        length--;
    }

    void searchStudent(int id)
    {
        Node *current = head;
        bool found = false;

        for (int i = 0; i < length; i++)
        {
            if (current->id == id)
            {
                cout << "ID: " << current->id << endl;
                cout << "Name: " << current->name << endl;
                cout << "CGPA: " << current->cgpa << endl;
                found = true;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << "Student Not Found" << endl;
        }
    }

    void calculateAverage()
    {
        double sum = 0.0;
        Node *current = head;
        for (int i = 0; i < length; i++)
        {
            sum += current->cgpa;
            current = current->next;
        }

        double result = sum / length;
        cout << "Average :" << result << endl;
    }

    void Display()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << "ID: " << curr->id << endl;
            cout << "Name: " << curr->name << endl;
            cout << "CGPA: " << curr->cgpa << endl;
            cout << "--------------------------" << endl;
            curr = curr->next;
        }
    }

};

int main()
{
    ManageList obj;
    int choice;
    int id;
    string name;
    double cgpa;
    do
    {
        cout << "Press 1 | Add Student" << endl;
        cout << "Press 2 | Remove Student" << endl;
        cout << "Press 3 | Search Student" << endl;
        cout << "Press 4 | Check Average" << endl;
        cout << "Press 5 | To Display" << endl;
        cout << "Press 6 | Exist Program" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter id :";
            cin >> id;
            cout << "Enter Name :";
            cin >> name;
            cout << "Enter CGPA :";
            cin >> cgpa;
            obj.addStudent(id, name, cgpa);
            cout<<"Student Add Successfully"<<endl;
            break;
        case 2:

            cout << "Enter the ID to remove :";
            cin >> id;
            obj.removeStudent(id);
            break;

        case 3:

            cout << "Enter the ID to search :";
            cin >> id;
            obj.searchStudent(id);
            break;

        case 4:

            obj.calculateAverage(); // Calculate total average of Cgpa
            break;

        case 5:

            obj.Display();
            break;
        default:

            cout << "Exit the Program Successfully " << endl;
            break;
        }

    } while (choice != 6);
}