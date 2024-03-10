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

// insert a node 
void insertNode(Node* &head,int data){
    Node* newNode = new Node(data);
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// printing the node
void printNode(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

int main()
{
    Node* n = new Node(1);

    Node* head = n;
    insertNode(head,2);

    printNode(head);
    
    return 0;
}