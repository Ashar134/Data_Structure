#include <iostream>
using namespace std;

class Node
{
private:
    int id;
    string name;
    string department;
    Node *right;
    Node *left;

    friend class BST;
    friend int main();

public:
    Node()
    {
        this->id = 0;
        this->name = "N/A";
        this->department = "N/A";
        right = NULL;
        left = NULL;
    }
    Node(int id, string name, string department)
    {
        this->id = id;
        this->name = name;
        this->department = department;
        right = NULL;
        left = NULL;
    }
};

class BST
{
private:
    Node *root;
    friend int main();

public:
    BST()
    {
        root = NULL;
    }

    Node *insert(Node *node, int id, string name, string department)
    {
        if (node == NULL)
        {
            Node *temp = new Node(id, name, department);

            if (root == NULL)
            {
                root = temp;
            }
            return temp;
        }

        if (node->id == id)
        {
            cout << "Already exist" << endl;
            return node;
        }
        else if (id > node->id)
        {
            node->right = insert(node->right, id, name, department);
        }
        else
        {
            node->left = insert(node->left, id, name, department);
        }

        return node;
    }

    Node *employeeSameAuthority(Node *node, int empId) // employee with same authority
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (node->right != NULL && node->right->id == empId)
        {
            return node->left;
        }
        else if (node->left != NULL && node->left->id == empId)
        {
            return node->right;
        }

        if (empId > node->id)
        {
            return employeeSameAuthority(node->right, empId);
        }
        else
        {
            return employeeSameAuthority(node->left, empId);
        }

        return NULL;
    }

    int checkDept(Node *node)
    {
        int leftCount = 0;
        int rightCount = 0;

        if (node == NULL)
        {
            return 0;
        }
        else if (checkDept(node->left))
        {
            leftCount++;
        }
        else if (checkDept(node->right))
        {
            rightCount++;
        }

        if (rightCount > leftCount) // Return which one is greater
        {
            return (rightCount + 1);
        }
        else
        {
            return (leftCount + 1);
        }
    }

    bool findSubordinate(Node *node, int empId)
    {
        if (node == NULL)
        {
            return false;
        }

        if (node->id == empId)
        {
            cout << "---------SEARCHING....--------" << endl;
            cout << "Employee Id : " << node->id << endl;
            cout << "Employee Name : " << node->name << endl;
            cout << "Department : " << node->department << endl;
            cout << "-----------------------" << endl;

            if (node->left != NULL)
            {
                cout << "-------SUBORDINATE-------" << endl;
                cout << "Employee Id : " << node->left->id << endl;
                cout << "Employee Name : " << node->left->name << endl;
                cout << "Department : " << node->left->department << endl;
                cout << "-----------------------" << endl;

                if (node->right != NULL)
                {
                    cout << "Employee Id : " << node->right->id << endl;
                    cout << "Employee Name : " << node->right->name << endl;
                    cout << "Department : " << node->right->department << endl;
                    cout << "-----------------------" << endl;
                }
            }

            return true;
        }

        return findSubordinate(node->left, empId) |
               findSubordinate(node->right, empId);
    }

    bool searchEmployee(Node *node, int empId)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->id == empId)
        {
            cout << "Employee Id : " << node->id << endl;
            cout << "Employee Name : " << node->name << endl;
            cout << "Department : " << node->department << endl;
            cout << "-----------------------" << endl;
            return true;
        }

        return searchEmployee(node->left, empId) |
               searchEmployee(node->right, empId);
    }

    void preOrder(Node *node)
    {

        if (node == NULL)
        {
            return;
        }
        cout << "id : " << node->id << " name : " << node->name
             << " department : " << node->department << endl;
        cout << "--------------------------------------" << endl;
        preOrder(node->left);
        preOrder(node->right);
    }
};

int main()
{

    BST obj;
    int choice;
    int id;
    string name;
    string department;
    int depth;
     Node *found = NULL;

    obj.insert(obj.root, 4, "Ali", "Ceo");
    obj.insert(obj.root, 2, "Ahmed", "Manager");
    obj.insert(obj.root, 1, "Kamran", "Programmer");
    obj.insert(obj.root, 3, "Abid ", "Developer");
    obj.insert(obj.root, 6, "Bilal", "Tester");
    obj.insert(obj.root, 5, "Ubiad", "Q/A");
    obj.insert(obj.root, 7, "Adil", "Finance");

    cout << "Press 1| Insert Employee" << endl;
    cout << "Press 2| Search Employee" << endl;
    cout << "Press 3| Employee with Same Authority" << endl;
    cout << "Press 4| Find Subordinates" << endl;
    cout << "Press 5| Check Depth" << endl;
    cout << "Press 6| Display All Employees" << endl;
    cout << "Press 7| Exit" << endl;

    do
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Enter employee ID: ";
            cin >> id;
            cout << "Enter employee name: ";
            cin >> name;
            cout << "Enter department: ";
            cin >> department;

            obj.insert(obj.root, id, name, department);
            cout << "Employee inserted successfully" << endl;
            break;

        case 2:

            cout << "Enter employee ID to search: ";
            cin >> id;
            if (obj.searchEmployee(obj.root, id))
            {
                cout << "Employee found" << endl;
            }
            else
            {
                cout << "Employee not found" << endl;
            }
            break;

        case 3:
            cout << "Enter employee ID to search: ";
            cin >> id;

            found = obj.employeeSameAuthority(obj.root, id);

            if (found == NULL)
            {
                cout << "No Employee Found With same Authority" << endl;
            }
            else
            {
                cout << "----------Found--------- " << endl;
                cout << "Employee Id : " << found->id << endl;
                cout << "Employee Name : " << found->name << endl;
                cout << "Department : " << found->department << endl;
                cout << "------------------------" << endl;
            }
            break;
        case 4:

            cout << "Enter employee ID to find subordinate : ";
            cin >> id;
            if (!obj.findSubordinate(obj.root, id))
            {
                cout << "Employee not found" << endl;
            }
            break;

        case 5:

            depth = obj.checkDept(obj.root);
            cout << "Depth :" << depth << endl;
            break;

        case 6:
            cout << "All Employees Detail :" << endl;
            obj.preOrder(obj.root);
            break;

        default:
            cout << "Thanks for using the System" << endl;
        }

    } while (choice != 7);

    return 0;
}