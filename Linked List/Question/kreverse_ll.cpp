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
    Node *temp = head;
    Node *newNode = new Node(data);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node *kReverse(Node *&head, int k)
{
    Node *temp = head;
    Node *prev = NULL;
    Node *forward = NULL;
    int count = 0;

    while (temp != NULL && count < k)
    {
        forward = temp->next;
        temp->next = prev;
        prev = temp;
        temp = forward;
        count++;
    }

    if (forward != NULL)
    {
        head->next = kReverse(forward, k);
    }
    return prev;
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

    cout << "Reversing the array with k = 2\n";
    Node *n = new Node(1);

    Node *head1 = n;
    printNode(head1);

    insertNode(head1, 2);
    insertNode(head1, 3);
    insertNode(head1, 4);
    insertNode(head1, 5);
    insertNode(head1, 6);
    printNode(head1);

    Node *reverse1 = kReverse(head1, 2);
    printNode(reverse1);
    //----------------------------------------------------------------
    cout << "\nReversing the array with k = 3\n";
    Node *n1 = new Node(1);
    Node *head2 = n1;
    printNode(head2);

    insertNode(head2, 2);
    insertNode(head2, 3);
    insertNode(head2, 4);
    insertNode(head2, 5);
    insertNode(head2, 6);
    printNode(head2);

    Node *reverse2 = kReverse(head2, 3);
    printNode(reverse2);

    return 0;
}