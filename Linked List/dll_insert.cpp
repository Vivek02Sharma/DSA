#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

// insert node at head
void insertAthead(Node* &head,int data){
    Node* newNode = new Node(data);

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// insert node at last
void insertAtlast(Node* &tail,int data){
    Node* newNode = new Node(data);

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// insert node at any position
void insertAtposition(Node* &head,Node* &tail,int pos,int data){
    Node* newNode = new Node(data);
    Node* temp = head;

    // insert at first position
    if(pos == 1){
        insertAthead(head,data);
        return;
    }

    int count = 1;

    while(count < pos - 1){
        temp = temp->next;
        count++;
    }
    // insert at last position
    if(temp->next == NULL){
        insertAtlast(tail,data);
        return;
    }

    // insert at middle position
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// printing the node
void printNode(Node* &head){
    Node* temp = head;

    cout<<"NULL ";
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main()
{
    Node* n = new Node(1);

    Node* head = n;

    insertAthead(head,2);
    insertAthead(head,3);
    insertAthead(head,4);
    insertAthead(head,5);

    printNode(head);
    cout<<endl;

    Node* tail = n;
    insertAtlast(tail,0);

    printNode(head);
    cout<<endl;

// insert at any position
    
    insertAtposition(head,tail,1,6); //first position
    printNode(head);
    cout<<endl;

    insertAtposition(head,tail,8,-1); //last position
    printNode(head);
    cout<<endl;

    insertAtposition(head,tail,3,-4); //middle position
    printNode(head);
    cout<<endl;

    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    return 0;
}