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

    bool findNode(Node *node, int findValue)
    {
        if (node == NULL)
        {
            return false;
        }

        if (node->value == findValue)
        {
            cout << "Output " << node->value;

            if (node->left != NULL)
            {
                cout << " " << node->left->value;
                if (node->right != NULL)
                {
                    cout << " " << node->right->value;
                }
                else
                {
                    cout << endl;
                    cout << "Child of node not found" << endl;
                }
            }
            else
            {
                cout << endl;
                cout << "Child of node not found" << endl;
            }
            return true;
            
        }

       return findNode(node->left, findValue) |
              findNode(node->right, findValue);


    }
};

int main()
{

    BST obj;
    int choice;
    int findNumber;
    obj.insert(obj.root, 4);
    obj.insert(obj.root, 2);
    obj.insert(obj.root, 7);
    obj.insert(obj.root, 1);
    obj.insert(obj.root, 3);

    cout << "Root: ";
    obj.preOrder(obj.root);
    cout << endl;

    cout << "Enter the Value to Find : ";
    cin >> findNumber;

    if (!obj.findNode(obj.root, findNumber))
    {
        cout << "[] Nothing Found" << endl;
    }
    return 0;
}