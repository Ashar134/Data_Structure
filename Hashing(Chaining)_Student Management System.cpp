#include <iostream>
using namespace std;

class Node
{
public:
    int serialNo;
    string rollno;
    string firstName;
    string fatherName;
    string department;
    string degree;
    Node *next;

    Node() // Constructor
    {
        serialNo = 0;
        rollno = "N/A";
        firstName = "N/A";
        fatherName = "N/A";
        department = "N/A";
        degree = "N/A";
        next = NULL;
    }

    Node(int serialNo, string rollno, string name, string fatherName, string department, string degree)
    {
        this->serialNo = serialNo;
        this->rollno = rollno;
        this->firstName = name;
        this->fatherName = fatherName;
        this->department = department;
        this->degree = degree;
        next = NULL;
    }
};

class linkList   //link list class 
{
private:
    Node *head;
    int length;

public:
    linkList()
    {
        head = NULL;
        length = 0;
    }

    void insert(int serialNo, string rollno, string firstName, string fatherName, string department, string degree)
    {
        Node *newNode = new Node(serialNo, rollno, firstName, fatherName, department, degree);

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

    Node *search(string rollno)
    {
        Node *current = head;

        while (current)
        {
            if (current->rollno == rollno)
            {
                return current;
            }
            current = current->next;
        }

        return NULL;
    }
};

class Hashing
{

private:
    int size;
    linkList *arr;  //Composition of linklist class

public:
    Hashing(int size)
    {
        arr = new linkList[size];   //Using dynamic arr to store hash table
        this->size = size;
    }

    int hashFunc(string rollno)
    {
        int numb1 = 0;
        int numb2 = 0;

        numb1 = 10 * (rollno[0] - '0');       // taking year from 22P-9346, "22"
        numb2 = numb1 + (rollno[1] - '0');

        //cout << " value:" << numb2 << endl;

        return numb2 % size;
    }

    void addingStudent(int serialNo, string rollno, string firstName, string fatherName, string department, string degree)
    {
        int index = hashFunc(rollno);   //Finding the index of the table where to place 

        arr[index].insert(serialNo, rollno, firstName, fatherName, department, degree);
    }

    Node *searchStudent(string rollno)
    {

        int index = hashFunc(rollno);
        return arr[index].search(rollno);  
    }

    ~Hashing()
    {
        delete[] arr;
    }
};

int main()
{

    char choice = 'y';
    string searchStudentRollno;
    Hashing obj(100); // Range for admission years 0-99

    //Insertion in the table 
    obj.addingStudent(9346, "22P-9346", "Ashar ", "Naveed", "Computer Science", "Software Engineer");
    obj.addingStudent(9321, "22P-9321", "Abdullah ", "Ali", "Computer Science", "Software Engineer");
    obj.addingStudent(3045, "20P-3045", "Talha ", "Waseem", "Computer Science", "Computer Science");
    obj.addingStudent(1310, "19P-1310", "Ahmed ", "Saleem", "Computer Science", "Software Engineer");
    obj.addingStudent(1345, "19P-1345", "Waqar ", "Ahmed", "Computer Science", "Artificial intelligence");
    obj.addingStudent(3457, "18P-3457", "Ali ", "Ahmed", "Computer Science", "Data Science");
    obj.addingStudent(1247, "18P-1247", "Hasan ", "Ali", "Humanities", "Psychology");
    

    do
    {

        cout << "-------STUDENT RECORD'S-------" << endl;
        cout << "Pattern '22P-9346'" << endl;
        cout << "RollNo to Found :";
        cin >> searchStudentRollno;
        cout << "------------------------------" << endl;

        Node *foundStudent = obj.searchStudent(searchStudentRollno);

        if (foundStudent)
        {
            cout << "-------RECORD FOUND-------" << endl;
            cout << "Name : " << foundStudent->firstName << endl;
            cout << "Father Name : " << foundStudent->fatherName << endl;
            cout << "Roll Number : " << foundStudent->rollno << endl;
            cout << "Department : " << foundStudent->department << endl;
            cout << "Degree Enrollment : " << foundStudent->degree << endl;

        }
        else
        {
            cout << "No record found" << endl;
        }
        cout << "----------------------------" << endl;
        cout << "Want to Exist y/n :";
        cin >> choice;

    } while (choice != 'y');
    
    cout << "Exist the Program" << endl;
    
    return 0;
}