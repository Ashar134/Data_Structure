#include <iostream>
using namespace std;

class Node
{
private:
    int value;
    Node *right;
    Node *left;

    friend class BST;
    friend int main();

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
        cout << node->value << "\t";
        preOrder(node->left);
        preOrder(node->right);
    }

    void deleteNode(Node *&node, int value)
    {
        if (node == nullptr)
        {
            cout << "Node not found" << endl;
            return;
        }

        if (value < node->value)
        {
            deleteNode(node->left, value);
        }
        else if (value > node->value)
        {
            deleteNode(node->right, value);
        }
        else
        {

            if (node->left == nullptr) // Node with no child or only one child
            {
                Node *temp = node->right;
                delete node;
                node = temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                node = temp;

            }
            else
            {
                Node *temp = node->left; // Maximum node in the left subtree
                while (temp->right != nullptr)
                {
                    temp = temp->right;
                }
                node->value = temp->value; // Copying the value
                deleteNode(node->left, temp->value);
            }
        }
    }
};

int main()
{
    BST obj;

    obj.insert(obj.root, 50);
    obj.insert(obj.root, 30);
    obj.insert(obj.root, 20);
    obj.insert(obj.root, 40);
    obj.insert(obj.root, 70);
    obj.insert(obj.root, 60);
    obj.insert(obj.root, 80);

    obj.preOrder(obj.root);
    cout << endl;

    obj.deleteNode(obj.root, 50); // deleting head
    cout << "Tree after deleting the head:" << endl;
    obj.preOrder(obj.root);
    cout << endl;

    obj.deleteNode(obj.root, 60); // deleting child
    cout << "Tree after deleting the child:" << endl;
    obj.preOrder(obj.root);
    cout << endl;
}
