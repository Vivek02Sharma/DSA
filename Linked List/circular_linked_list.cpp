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
};

// inserting node into circular linked list
void insertCircularNode(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    Node *temp = tail;

    // create a new node if tail is empty
    if (tail == NULL)
    {
        tail = newNode;
        newNode->next = newNode;
        return;
    }
    else
    {
        // insert a node after tail
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

// printing the circular linked list
void printCircularNode(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "Empty Circular Linked List" << endl;
        return;
    }

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

    n->next = n; // pointing node to itself to create a circular linked list

    Node *tail = n;

    printCircularNode(tail);

    insertCircularNode(tail, 2);
    insertCircularNode(tail, 3);
    insertCircularNode(tail, 4);
    insertCircularNode(tail, 5);

    printCircularNode(tail);

    return 0;
}