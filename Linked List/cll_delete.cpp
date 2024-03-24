#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }

    ~Node()
    {
        cout << "Deleting node with data : " << data << endl;

        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

// inserting a node
void insertNode(Node *&tail, int data)
{
    Node *newNode = new Node(data);

    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

// deleting a node
void deleteNode(Node *&tail, int data)
{
    Node *prev = tail;
    Node *temp = prev->next;

    while (temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == tail)
    {
        tail = prev;
    }
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
}

// printing node
void printNode(Node *&tail)
{
    Node *temp = tail->next;

    cout << "->";
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

int main()
{
    Node *n = new Node(1);
    n->next = n;
    Node *tail = n;
    printNode(tail);

    insertNode(tail, 2);
    insertNode(tail, 3);
    insertNode(tail, 4);
    insertNode(tail, 5);
    printNode(tail);

    deleteNode(tail, 1);
    printNode(tail);

    deleteNode(tail, 2);
    printNode(tail);

    deleteNode(tail, 5);
    printNode(tail);

    return 0;
}