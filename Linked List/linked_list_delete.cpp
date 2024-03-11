#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void printNode(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

void insertNode(Node* &head,int data){
    Node* newNode = new Node(data);
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node* &head,int data){
    Node* temp = head;
    Node* prev = NULL;

    // deleting first node
    if(temp->data == data){
        head = head->next;
        return;
    }

    // deleting any node or last node
    while(temp->data != data){
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    temp = NULL;
}

int main()
{
    Node* n = new Node(1);
    insertNode(n,2);
    insertNode(n,3);
    insertNode(n,4);
    insertNode(n,5);
    Node* head = n;
    printNode(head);

    cout<<"First node deleted : ";
    deleteNode(head,1);
    printNode(head);

    cout<<"Second node deleted : ";
    deleteNode(head,2);
    printNode(head);
    
    cout<<"Last node deleted : ";
    deleteNode(head,5);
    printNode(head);

    return 0;
}