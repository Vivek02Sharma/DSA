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

    ~Node(){
        cout<<"Deleting node of data : "<<data<<endl;

        if(next != NULL){
            delete next;
            next = NULL;
        }
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

void deleteNode(Node* &head,int data){
    Node* temp = head;
    Node* prev = NULL;

    // deletion of first node
    if(temp->data == data){
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else{
    // deletion of any node or last node
    while(temp->data != data){
        prev = temp;
        temp = temp->next;
    }
    temp->prev = NULL;
    prev->next = temp->next;
    temp->next = NULL;
    delete temp;
    }
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
    Node* tail = n;

    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    
    printNode(head);
    cout<<endl;
    cout<<"head : "<<head->data<<endl<<endl;

    // delete first node
    deleteNode(head,1);
    printNode(head);
    cout<<endl;
    cout<<"head : "<<head->data<<endl<<endl;

    // delete second node
    deleteNode(head,2);
    printNode(head);
    cout<<endl;
    cout<<"head : "<<head->data<<endl<<endl;

    // delete middle node
    deleteNode(head,3);
    printNode(head);
    cout<<endl;
    cout<<"head : "<<head->data<<endl<<endl;

    // delete last node
    deleteNode(head,6);
    printNode(head);
    cout<<endl;
    cout<<"head : "<<head->data<<endl;

    return 0;
}