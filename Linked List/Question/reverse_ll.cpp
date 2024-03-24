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

void insertNode(Node *&head, int data)
{
    Node *newNode = new Node(data);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void reverseNode(Node *&head)
{
    Node *temp = head;
    Node *prev = NULL;
    Node *forward = NULL;

    while (temp != NULL)
    {
        forward = temp->next;
        temp->next = prev;
        prev = temp;
        temp = forward;
    }
    head = prev;
}

void printNode(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *n = new Node(1);
    Node *head = n;
    printNode(head);

    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    printNode(head);

    reverseNode(head);
    printNode(head);

    return 0;
}

