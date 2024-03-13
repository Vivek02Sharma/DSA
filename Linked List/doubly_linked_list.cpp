#include <iostream>
using namespace std;

class Node{
    public:
    Node* next;
    Node* prev;
    int data;
    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

// inserting node into doubly linked list
void insert(Node* &head, int data){
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// printing the node
void printNode(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    Node* n = new Node(1);

    Node* head = n;

    insert(head,2);
    
    printNode(head);
    cout<<endl;

    cout<<"prev : "<<head->prev<<endl;
    cout<<"next : "<<head->next<<endl;

    cout<<"head : "<<head->data;
    return 0;
}