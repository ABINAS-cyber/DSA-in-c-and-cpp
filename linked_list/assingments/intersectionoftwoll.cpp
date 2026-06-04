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
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}


Node* intersection(Node* head1,Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1!=temp2){
        temp1 = (temp1==NULL) ? head2 : temp1->next;
        temp2 = (temp2==NULL) ? head1 : temp2->next;
    }
    return temp1; // or temp2, both are same at this point
}

int main(){
    int n1,n2;
    cout<<"enter number of nodes for list 1: ";
    cin>>n1;
    Node* head1 = creationlist(n1);
    cout<<"enter number of nodes for list 2: ";
    cin>>n2;
    Node* head2 = creationlist(n2);
    
    // For testing, we can create an intersection manually
    // For example, let's connect the last node of list 2 to the second node of list 1
    if(head1!=NULL && head2!=NULL){
        Node* temp = head1->next; // second node of list 1
        Node* tail2 = head2;
        while(tail2->next!=NULL) tail2 = tail2->next; // find last node of list 2
        tail2->next = temp; // create intersection
    }
    
    Node* intersectNode = intersection(head1, head2);
    if(intersectNode!=NULL){
        cout<<"Intersection at node with data: "<<intersectNode->data<<endl;
    }else{
        cout<<"No intersection found."<<endl;
    }
    
    return 0;
}
