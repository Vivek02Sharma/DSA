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

void insertAthead(Node* &head,int data){
    Node* newnode = new Node(data);

    newnode->next = head;
    head = newnode;
}

void insertAttail(Node* &tail,int data){
    Node* newnode = new Node(data);
    tail->next = newnode;
    tail = newnode;
}

void insertAtposition(Node* &head,Node* &tail,int pos,int data){
    Node* newNode = new Node(data);
    Node* temp = head;

// insert at start
    if(pos == 1){
        insertAthead(head,data);
        return;
    }

    int count = 1;
    while(count < pos - 1){
        temp = temp->next;
        count++;
    }

    // insert at last
    if(temp->next == NULL){
        insertAttail(tail,data);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

}

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
    Node* n1 = new Node(1);
    cout<<n1->data<<endl<<n1->next<<endl;
    
    // insert at head
    Node* head = n1;
    insertAthead(head,-1);
    printNode(head);

// insert at tail
    Node* tail = n1;
    insertAttail(tail,2);
    insertAttail(tail,3);
    insertAttail(tail,4);
    printNode(head);

// insert at any position
    insertAtposition(head,tail,1,-2);
    printNode(head);

    insertAtposition(head,tail,3,0);
    printNode(head);

    insertAtposition(head,tail,8,5);
    printNode(head);
    
    // checking the head and tail pointer
    cout<<"head : "<<head->data<<endl;
    cout<<"tail : "<<tail->data<<endl;

    return 0;
}


