#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* creationlist(int n){
    Node* head = NULL , *tail = NULL;
    for(int i = 0 ; i < n;i++){
        cout<<"Enter the data "<<i+1<< ": ";
        int data;
        cin>>data;
        Node *newnode = new Node;
        newnode->data=data;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    return head;
}

void display(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void mergell(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            cout<<temp1->data<<"->";
            temp1 = temp1->next;
        }else{
            cout<<temp2->data<<"->";
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL){
        cout<<temp1->data<<"->";
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        cout<<temp2->data<<"->";
        temp2 = temp2->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    int n1, n2;
    cout<<"Enter the number of nodes in first list: ";
    cin>>n1;
    Node* head1 = creationlist(n1);
    cout<<"Enter the number of nodes in second list: ";
    cin>>n2;
    Node* head2 = creationlist(n2);
    cout<<"Merged list: ";
    mergell(head1, head2);
    return 0;
}
