#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* creationlist(int n){
    Node* head = NULL,* tail=NULL;
    for(int i=0;i<n;i++){
        Node* newnode = new Node;
        cout<<"enter data for node "<<i+1<<": ";
        cin>>newnode->data;
        newnode->next = NULL;
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    return head;
}

void display(Node* head){
    Node* temp = head;
    int count = 0; // safeguard against infinite loop
    while(temp!=NULL && count < 50){ // limit traversal
        cout<<temp->data<<"->";
        temp = temp->next;
        count++;
    }
    if(temp==NULL) cout<<"NULL"<<endl;
    else cout<<"...cycle detected, stopping display"<<endl;
}

Node* createcycle(Node* head,int pos){
    if(pos==-1) return head;
    Node* temp = head;
    Node* startnode = NULL;
    int count = 0;
    while(temp->next!=NULL){
        if(count==pos) startnode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
    return head;
}

bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main(){
    cout<<"how many nodes you want to create?"<<endl;
    int n; cin>>n;
    Node* head = creationlist(n);
    display(head);
    cout<<"enter the position where you want to create cycle(-1 for no cycle)"<<endl;
    int pos; cin>>pos;
    createcycle(head,pos);  

    if(detectCycle(head)){
        cout<<"Cycle detected in the linked list!"<<endl;
    }else{
        cout<<"No cycle detected."<<endl;
        display(head);
    }
}
