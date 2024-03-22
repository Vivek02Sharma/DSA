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

// inserting a node at start
void insertAthead(Node *&head, int data)
{
    Node *temp = head;
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = newNode;
        return;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// inserting node at last
void insertAtlast(Node *&tail, int data)
{
    Node *newNode = new Node(data);
    Node *temp = tail;

    while (temp->next != tail->next)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    tail = newNode;
}

void insertAtposition(Node *&head, Node *&tail, int pos, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;

    // insert at first position
    if (pos == 1)
    {
        insertAthead(head, data);
        return;
    }
    else
    {
        int count = 1;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }

        // insert at last position
        if (temp->next == tail->next)
        {
            insertAtlast(tail, data);
            return;
        }

        // insert at middle position
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// printing a node
void printCircularNode(Node *&head)
{
    if (head == NULL)
    {
        cout << "Empty Circular Linked List" << endl;
        return;
    }

    Node *temp = head;

    cout << "->";
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    Node *n = new Node(1);
    n->next = n;

    Node *head = n;
    Node *tail = n;
    printCircularNode(head);

    insertAthead(head, 2);
    insertAthead(head, 3);

    insertAtlast(tail, -2);
    insertAtlast(tail, -3);

    // inserting a node at middle position
    insertAtposition(head, tail, 4, 0);
    insertAtposition(head, tail, 5, -1);

    // inserting a node at first position
    insertAtposition(head, tail, 1, 4);

    // inserting a node at last position
    insertAtposition(head, tail, 9, -4);

    printCircularNode(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    return 0;
}