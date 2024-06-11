#include <iostream>
using namespace std;
void IsAVL(int check);

class Node
{
private:
    int value;
    Node *right;
    Node *left;
    int height;

    friend class BST;
    friend int main();

public:
    Node()
    {
        this->value = 0;
        right = NULL;
        left = NULL;
        height = 0;
    }
    Node(int value)
    {
        this->value = value;
        right = NULL;
        left = NULL;
        height = 1;
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

        node->height = updateHeight(node);
        return node;
    }

    int getHeight(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }

    int updateHeight(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int leftheight = getHeight(node->left);
        int rightheight = getHeight(node->right);

        return 1 + ((leftheight > rightheight) ? leftheight : rightheight);
    }

    int getBalance(Node *node)
    {
        return getHeight(node->left) - getHeight(node->right);
    }

    bool checkAVL(Node *node) // Checking AVL or not
    {
        if (node == NULL)
        {
            return true;
        }

        int balance = getBalance(node);

        cout << "Node value : " << node->value << " Height : " << getHeight(node)
             << " Balance : " << balance << endl;

        if (balance == 0 || balance == 1 || balance == -1)
        {
            checkAVL(node->left);
            checkAVL(node->right);
        }
        else
        {
            return false;
        }

        return true;
    }

    void preOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->value << "\t";
        preOrder(node->left);
        preOrder(node->right);
    }
};

int main()
{
    BST obj;
    BST tree2;
    int value;
    // Tree 1
    obj.insert(obj.root, 50);
    obj.insert(obj.root, 30);
    obj.insert(obj.root, 20);
    obj.insert(obj.root, 40);
    obj.insert(obj.root, 70);
    obj.insert(obj.root, 60);
    obj.insert(obj.root, 80);

    value = obj.checkAVL(obj.root);
    IsAVL(value);

    obj.preOrder(obj.root);
    cout << endl;

    cout << "--------Second Tree--------" << endl;

    // Tree 2
    tree2.insert(tree2.root, 15);
    tree2.insert(tree2.root, 10);
    tree2.insert(tree2.root, 5);

    value = tree2.checkAVL(tree2.root);
    IsAVL(value);

    tree2.preOrder(tree2.root);
    cout << endl;
}

void IsAVL(int check)
{
    if (check == 1)
    {
        cout << "Tree is AVL " << endl;
    }
    else
    {
        cout << "Tree is not an AVL" << endl;
    }
}