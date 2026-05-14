#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head = NULL, *tail = NULL;

void creation(){
    Node * newnode = new Node;
    cout<<"Enter the data: ";
    cin>>newnode->data;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }
    else{
        tail->next = newnode;
        tail = newnode;
    }
}

void display(){
    Node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    if(temp->next==NULL){
        cout<<temp->data<<"->NULL"<<endl;
    }
}

void insertbetween(){
    Node* newnode = new Node;
    cout<<"Enter the data to enter into between node: ";
    int item;
    cin>>item;
    cout<<"Enter the location to insert: ";
    int loc1;
    cin>>loc1;
    cout<<"Enter the location to insert: ";
    int loc2;
    cin>>loc2;
    newnode->data = item;
    if(head==NULL){
        newnode->next=NULL;
        head=newnode;
    }
    else{
        Node* temp= head;
        while (temp->data!=loc1 && temp->data!=loc2)
        {
            temp=temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    cout<< "\n" <<"One Node inserted!!!"<<endl;
}

int main(){
    int n;
    cout<<"How many nodes? ";
    cin>>n;
    for(int i=0;i<n;i++){
        creation();
    }
    display();
    insertbetween();
    display();
    return 0;
}