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
    Node *newnode = new Node;
    Node *temp;
    int pos,item,i=1;
    cout<<"Enter the position to enter the data: ";
    cin>>pos;
    cout<<"Enter the data to enter into between node: ";
    cin>>item;
    if(newnode==NULL){
        cout<<"Overflow";
    }
    else{
        newnode->data = item;
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
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
