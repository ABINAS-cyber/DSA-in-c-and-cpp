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


void begininsert(){
Node *newnode = new Node;
int item;
cout<<"Enter the data to enter into begin node: ";
cin>>item;
if(newnode==NULL){
    cout<<"Overflow";
}
else{
    newnode->data = item;
    newnode->next = head;
    head = newnode;
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


int main(){
    int n;
    cout<<"How many nodes ?";
    cin>>n;
    for(int i=0; i<n; i++){
        creation();
    }
    display();
    begininsert();
    display();
    return 0;
}