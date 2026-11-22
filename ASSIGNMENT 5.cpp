#include <iostream>
#include <stack>
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

    void insert(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;

        if(root == NULL)
        {
            root = newnode;
            return;
        }

        node *temp = root;
        node *parent = NULL;

        while(temp != NULL)
        {
            parent = temp;

            if(value < temp->data)
                temp = temp->left;
            else if(value > temp->data)
                temp = temp->right;
            else
            {
                cout << "Duplicate value not inserted.";
                delete newnode;
                return;
            }
        }

        if(value < parent->data)
            parent->left = newnode;
        else
            parent->right = newnode;
    }

    void build()
    {
        int n, value;

        cout << "\nEnter number of nodes: ";
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cout << "Enter value: ";
            cin >> value;
            insert(value);
        }
    }

    void inorder()
    {
        stack<node*> st;
        node *current = root;

        cout << "\nInorder Traversal: ";

        while(current != NULL || !st.empty())
        {
            while(current != NULL)
            {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();

            cout << current->data << " ";

            current = current->right;
        }

        cout << endl;
    }

    void preorder()
    {
        if(root == NULL)
            return;

        stack<node*> st;
        st.push(root);

        cout << "\nPreorder Traversal: ";

        while(!st.empty())
        {
            node *current = st.top();
            st.pop();

            cout << current->data << " ";

            if(current->right != NULL)
                st.push(current->right);

            if(current->left != NULL)
                st.push(current->left);
        }

        cout << endl;
    }
};

int main()
{
    binary tree;
    int choice;

    do
    {
        cout << "\n========== BST Menu ==========";
        cout << "\n1. Create Binary Search Tree";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Preorder Traversal";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                tree.build();
                break;

            case 2:
                tree.inorder();
                break;

            case 3:
                tree.preorder();
                break;

            case 4:
                cout << "Exiting Program...";
                break;

            default:
                cout << "Invalid Choice!";
        }

    } while(choice != 4);

    return 0;
}
