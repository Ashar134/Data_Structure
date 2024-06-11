#include <iostream>
using namespace std;

class Node
{
private:
    string search;
    int highPriority;
    Node *left;
    Node *right;
    int height;
    friend class AVL;

public:
    Node()
    {
        search = "N/A";
        highPriority = 0;
        left = NULL;
        right = NULL;
        height = 1;
    }

    Node(string search, int highPriority)
    {
        this->search = search;
        this->highPriority = highPriority;
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
        root = nullptr;
    }

    Node *insert(Node *node, string search_word, int priority)
    {

        if (node == NULL)
        {
            Node *node = new Node(search_word, priority);

            if (root == NULL)
            {
                root = node;
            }
            return node;
        }

        if (priority < node->highPriority)
        {
            node->left = insert(node->left, search_word, priority);
        }
        else if (priority > node->highPriority)
        {
            node->right = insert(node->right, search_word, priority);
        }
        else
        {
            return node;
        }

        node->height = updateHeight(node);

        int balance = getBalance(node);

        if (balance > 1)
        {
            if (priority < node->left->highPriority) // Left Left
            {
                return rightRotation(node);
            }
            else // Left Right
            {
                return leftRightRotation(node);
            }
        }
        else if (balance < -1)
        {
            if (priority > node->right->highPriority) // Right Right
            {
                return leftRotation(node);
            }

            else // Right Left
            {
                return rightLeftRotation(node);
            }
        }

        return node;
    }

    int getHeight(Node *node)
    {
        if (node == nullptr)
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

    Node *rightRotation(Node *A)
    {
        Node *temp = A->left;
        A->left = temp->right;
        temp->right = A;

        A->height = updateHeight(A); // Updating the height
        temp->height = updateHeight(temp);

        if (A == root) // Updating the  root
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

        A->height = updateHeight(A); // Update heights
        temp->height = updateHeight(temp);

        if (A == root) // Updating the root
        {
            root = temp;
        }

        return temp;
    }

    int getBalance(Node *node)
    {
        return getHeight(node->left) - getHeight(node->right);
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

    void suggestiononSearch(Node *node, string value)
    {
        if (node == nullptr)
        {
            return;
        }

        suggestiononSearch(node->right, value);

        int len1 = calculateLength(node->search);
        int len2 = calculateLength(value);

        if (len1 >= len2)
        {
            bool found = true;

            for (int i = 0; i < len2; ++i)
            {
                if (node->search[i] != value[i])
                {
                    found = false;
                    break;
                }
            }

            if (found)
            {
                cout << node->search << endl;
                    
            }
        }

        suggestiononSearch(node->left, value);
    }

    int calculateLength(string str)
    {
        int length = 0;

        while (str[length] != '\0')
        {
            length++;
        }

        return length;
    }

    void preOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->search << "(" << node->highPriority << ")"
             << "\t";
        preOrder(node->left);
        preOrder(node->right);
    }
};

int main()
{
    AVL obj;
    string searching;

    obj.insert(obj.root, "car for sale in pakistan", 15);
    obj.insert(obj.root, "calendar of islamic month", 10);
    obj.insert(obj.root, "cat food", 13);
    obj.insert(obj.root, "convert pdf to word", 5);
    obj.insert(obj.root, "is apple good for health ", 4);
    obj.insert(obj.root, "flex Student", 20);
    obj.insert(obj.root, "flat prices in Karachi ", 30);
    obj.insert(obj.root, "flat prices in Pakistan ", 25);
    obj.insert(obj.root, "flat prices in Islamabad ", 8);

    cout << "-------Search Bar --------- " << endl;
    cin >> searching;
    cout << "--------------------------- " << endl;
    cout << "Searching....." << endl;

    obj.suggestiononSearch(obj.root, searching);
   
  
    // obj.preOrder(obj.root);

    return 0;
}
