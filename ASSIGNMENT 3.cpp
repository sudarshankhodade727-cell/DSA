#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void insertBeginning(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;

    cout << "Book ID inserted at beginning.\n";
}

void insertEnd(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Book ID inserted at end.\n";
}

void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    cout << "Deleted Book ID: " << head->data << endl;
    head = head->next;
    delete temp;
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    cout << "Book IDs: ";

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n----- Library Book Management -----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete from Beginning\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Book ID: ";
                cin >> value;
                insertBeginning(value);
                break;

            case 2:
                cout << "Enter Book ID: ";
                cin >> value;
                insertEnd(value);
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
