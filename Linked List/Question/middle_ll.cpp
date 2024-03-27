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

int getlength(Node *&head)
{
    Node *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len += 1;
        temp = temp->next;
    }

    return len;
}

void middle_linked_list(Node *&head)
{
    Node *temp = head;
    int middle = (getlength(head) / 2) + 1;
    int count = 1;
    while(count < middle){
        temp = temp->next;
        count++;
    }
    cout<<temp->data<<endl;
}

int main()
{
    Node *n = new Node(1);

    Node *head = n;
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    printNode(head);

    cout << getlength(head) << endl;

    middle_linked_list(head);
    return 0;
}