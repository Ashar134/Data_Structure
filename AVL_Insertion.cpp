#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
    ~Node();
};

class AVL
{
private:
    Node *root;
    friend int main();

public:
    AVL()
    {
        root = NULL;
    }

    Node *insert(Node *node, int value)
    {
        if (node == NULL)
        {
            Node *temp = new Node(value);

            if (root == NULL)
            {
                root = temp;
            }
            return temp;
        }

        if (node->data == value)
        {
            cout << "Already exist" << endl;
            return node;
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }
        else
        {
            node->left = insert(node->left, value);
        }

        node->height = updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1)
        {
            if (value < node->left->data)     // Left Left
            {
                return rightRotation(node);
            }
            else    // Left Right
            {
                return leftRightRotation(node);
            }
        }
        else if (balance < -1)
        {
            if (value > node->right->data)     // Right Right
            {
                return leftRotation(node);
            }

            else     // Right Left
            {
                return rightLeftRotation(node);
            }
        }

        return node;
    }

    Node *rightRotation(Node *A)
    {
        Node *temp = A->left;
        A->left = temp->right;
        temp->right = A;

        A->height = updateHeight(A);     // Updating the height
        temp->height = updateHeight(temp);

        if (A == root)      // Updating the  root
        {
            root = temp;
        }

        return temp;
    }

    Node *leftRotation(Node *A)
    {
        Node *temp = A->right;
        A->right = temp->left;
        temp->left = A;

        A->height = updateHeight(A);     // Update heights
        temp->height = updateHeight(temp);

        if (A == root)                  // Updating the root
        {
            root = temp;
        }

        return temp;
    }

    Node *rightLeftRotation(Node *A)
    {
        A->right = rightRotation(A->right);
        return leftRotation(A);
    }

    Node *leftRightRotation(Node *A)
    {
        A->left = leftRotation(A->left);
        return rightRotation(A);
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

    void preOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << "[" << getBalance(node) << "]"<< "\t";   //Printing every node balance
        preOrder(node->left);
        preOrder(node->right);
    }
};

int main()
{
    AVL obj1, obj2, obj3;

    cout << "--------First Tree--------" << endl;
    obj1.insert(obj1.root, 15);
    obj1.insert(obj1.root, 10);
    obj1.insert(obj1.root, 5);
    obj1.preOrder(obj1.root);
    cout << endl;

    cout << "--------Second Tree--------" << endl;
    obj2.insert(obj2.root, 20);
    obj2.insert(obj2.root, 30);
    obj2.insert(obj2.root, 25);
    obj2.preOrder(obj2.root);
    cout << endl;

    cout << "--------Third Tree--------" << endl;
    obj3.insert(obj3.root, 20);
    obj3.insert(obj3.root, 15);
    obj3.insert(obj3.root, 17);
    obj3.preOrder(obj3.root);

    return 0;
}
