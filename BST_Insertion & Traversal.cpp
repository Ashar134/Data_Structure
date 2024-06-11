#include <iostream>
using namespace std;

class Node
{
private:
    int value;
    Node *right;
    Node *left;

public:
    Node()
    {
        this->value = 0;
        right = NULL;
        left = NULL;
    }
    Node(int value)
    {
        this->value = value;
        right = NULL;
        left = NULL;
    }

    friend class BST;
    friend int main();
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

    Node *insert(Node *node, int val)
    {
        if (node == NULL)
        {
            Node *temp = new Node(val);

            if (root == NULL)
            {
                root = temp;
            }
            return temp;
        }

        if (node->value == val)
        {
            cout << "Already exist" << endl;
            return node;
        }
        else if (val > node->value)
        {
            node->right = insert(node->right, val);
        }
        else
        {
            node->left = insert(node->left, val);
        }

        return node;
    }

    void inOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        inOrder(node->left);
        cout << node->value;
        inOrder(node->right);
    }

    void preOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->value;
        preOrder(node->left);
        preOrder(node->right);
    }

    void postOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value;
    }

    Node *smallestNumber(Node *node)
    {
        if (node->left == NULL)
        {
            return node;
        }

        return smallestNumber(node->left);
    }

    int totalNodes(Node *node)
    {
        int count = 1;
        if (node == nullptr)
        {
            return 0;
        }

        return (count + totalNodes(node->left) + totalNodes(node->right));
    }
};

int main()
{
    BST obj;
    int choice;
    int value;

    cout << "----- MENU -----" << endl;
    cout << "Press 1 | Insert Element" << endl;
    cout << "Press 2 | For In-Order Traversal" << endl;
    cout << "Press 3 | For Pre-Order Traversal" << endl;
    cout << "Press 4 | For Post-Order Traversal" << endl;
    cout << "Press 5 | To Find Smallest Number" << endl;
    cout << "Press 6 | To Count Total Nodes" << endl;
    cout << "Press 7 | To Exist " << endl;

    do
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value : ";
            cin >> value;
            obj.insert(obj.root, value);
            cout << "---------------" << endl;
            break;
        case 2:
            cout << "In-Order : ";
            obj.inOrder(obj.root);
            cout << endl;
            cout << "---------------" << endl;
            break;
        case 3:
            cout << "Pre-Order : ";
            obj.preOrder(obj.root);
            cout << endl;
            cout << "---------------" << endl;
            break;
        case 4:
            cout << "Post-Order : ";
            obj.postOrder(obj.root);
            cout << endl;
            cout << "---------------" << endl;
            break;
        case 5:
        {
            Node *smallest = obj.smallestNumber(obj.root);
            cout << "Smallest Number: " << smallest->value << endl;
            cout << "---------------" << endl;
            break;
        }
        case 6:
            cout << "Total Nodes: " << obj.totalNodes(obj.root) << endl;
            cout << "---------------" << endl;
            break;

        default:
            cout << "Thanks for using the System " << endl;
        }
    } while (choice != 7);

    return 0;
}

// int main()
// {

//     BST obj;
//     int choice;
//     obj.insert(obj.root, 4);

//     obj.insert(obj.root, 2);
//     obj.insert(obj.root, 1);
//     obj.insert(obj.root, 3);

//     obj.insert(obj.root, 6);
//     obj.insert(obj.root, 5);
//     obj.insert(obj.root, 7);

//     cout << "In-Order " << endl;
//     obj.inOrder(obj.root);
//     cout << endl;

//     cout << "Pre-Order " << endl;
//     obj.preOrder(obj.root);
//     cout << endl;

//     cout << "Post-Order " << endl;
//     obj.postOrder(obj.root);
//     cout << endl;

//     Node *smallestNumber = obj.smallestNumber(obj.root);
//     cout << "Smallest Number : " << smallestNumber->value << endl;

//     cout << "Total Node : "<< obj.totalNodes(obj.root) << endl;

//     return 0;
// }