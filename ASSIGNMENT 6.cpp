#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
    Node *root;
    Node *copyRoot;

public:

    BST()
    {
        root = NULL;
        copyRoot = NULL;
    }

    Node* Insert(Node *root, int value)
    {
        if(root == NULL)
        {
            return new Node(value);
        }

        if(value < root->data)
        {
            root->left = Insert(root->left, value);
        }
        else if(value > root->data)
        {
            root->right = Insert(root->right, value);
        }
        else
        {
            cout << "Duplicate Value!" << endl;
        }

        return root;
    }

    void InsertNode()
    {
        int n, value;

        cout << "Enter number of nodes: ";
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cout << "Enter value: ";
            cin >> value;

            root = Insert(root, value);
        }
    }

    void LevelOrder(Node *root)
    {
        if(root == NULL)
        {
            cout << "Tree is Empty!" << endl;
            return;
        }

        queue<Node*> q;

        q.push(root);

        while(!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if(temp->left != NULL)
            {
                q.push(temp->left);
            }

            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }

        cout << endl;
    }

    Node* CopyTree(Node *root)
    {
        if(root == NULL)
        {
            return NULL;
        }

        Node *newNode = new Node(root->data);

        newNode->left = CopyTree(root->left);

        newNode->right = CopyTree(root->right);

        return newNode;
    }

    int Height(Node *root)
    {
        if(root == NULL)
        {
            return -1;
        }

        int leftHeight = Height(root->left);

        int rightHeight = Height(root->right);

        if(leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }
        else
        {
            return rightHeight + 1;
        }
    }

    void PrintLeafNodes(Node *root)
    {
        if(root == NULL)
        {
            return;
        }

        if(root->left == NULL && root->right == NULL)
        {
            cout << root->data << " ";
            return;
        }

        PrintLeafNodes(root->left);

        PrintLeafNodes(root->right);
    }

    void DisplayOriginal()
    {
        cout << "Original BST (Level Order): ";
        LevelOrder(root);
    }

    void CopyBST()
    {
        if(root == NULL)
        {
            cout << "Tree is Empty!" << endl;
            return;
        }

        copyRoot = CopyTree(root);

        cout << "BST Copied Successfully!" << endl;
    }

    void DisplayCopied()
    {
        cout << "Copied BST (Level Order): ";
        LevelOrder(copyRoot);
    }

    void FindHeight()
    {
        int h = Height(root);

        cout << "Height of BST = " << h << endl;
    }

    void DisplayLeaves()
    {
        if(root == NULL)
        {
            cout << "Tree is Empty!" << endl;
            return;
        }

        cout << "Leaf Nodes are: ";

        PrintLeafNodes(root);

        cout << endl;
    }
};

int main()
{
    BST tree;
    int choice;

    do
    {
        cout << "\n===== BINARY SEARCH TREE MENU =====";
        cout << "\n1. Insert Node";
        cout << "\n2. Display Original BST (Level Order)";
        cout << "\n3. Copy BST";
        cout << "\n4. Display Copied BST (Level Order)";
        cout << "\n5. Find Height of BST";
        cout << "\n6. Display Leaf Nodes";
        cout << "\n7. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                tree.InsertNode();
                break;

            case 2:
                tree.DisplayOriginal();
                break;

            case 3:
                tree.CopyBST();
                break;

            case 4:
                tree.DisplayCopied();
                break;

            case 5:
                tree.FindHeight();
                break;

            case 6:
                tree.DisplayLeaves();
                break;

            case 7:
                cout << "Exiting Program...";
                break;

            default:
                cout << "Invalid Choice!";
        }

    } while(choice != 7);

    return 0;
}
