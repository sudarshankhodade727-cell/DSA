#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class binary
{
private:
    node *root;

public:
    binary()
    {
        root = NULL;
    }

    node* create()
    {
        int value;

        cout << "Enter node value (-1 for no node): ";
        cin >> value;

        if (value == -1)
            return NULL;

        node *newnode = new node;
        newnode->data = value;

        cout << "Enter left child of " << value << ": " << endl;
        newnode->left = create();

        cout << "Enter right child of " << value << ": " << endl;
        newnode->right = create();

        return newnode;
    }

    void build()
    {
        cout << "\nCreate Binary Tree\n";
        root = create();
    }

    void inorder(node *temp)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }

    void preorder(node *temp)
    {
        if (temp == NULL)
            return;

        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }

    void postorder(node *temp)
    {
        if (temp == NULL)
            return;

        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }

    void displayInorder()
    {
        cout << "\nInorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder()
    {
        cout << "\nPreorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder()
    {
        cout << "\nPostorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main()
{
    binary tree;
    int choice;

    do
    {
        cout << "\n========== Binary Tree Menu ==========";
        cout << "\n1. Create Binary Tree";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                tree.build();
                break;

            case 2:
                tree.displayInorder();
                break;

            case 3:
                tree.displayPreorder();
                break;

            case 4:
                tree.displayPostorder();
                break;

            case 5:
                cout << "Exiting Program...";
                break;

            default:
                cout << "Invalid Choice!";
        }

    } while(choice != 5);

    return 0;
}
