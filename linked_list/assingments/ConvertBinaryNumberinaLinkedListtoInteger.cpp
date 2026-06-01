#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node *creationlist(int n){
    Node* head=NULL , *tail=NULL;
    for(int i=0;i<n;i++){
        cout<<"enter the data "<<i+1 <<":";
        int data;
        cin>>data;
        Node* newnode=new Node;
        newnode->data=data;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    return head;
}


void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int getDecimalValue(Node* head) {
    int num = 0;
    while (head != NULL) {
        // Shift left by 1 and bitwise OR with current node's data
        num = (num << 1) | head->data; 
        head = head->next;
    }
    return num;
}

int main() {
    int n;
    cout << "How many nodes? : ";
    cin >> n;
    
    // 1. Create the list
    Node* head = creationlist(n);
    
    // 2. Display the list
    cout << "\nLinked List: ";
    display(head);
    
    // 3. Calculate and print the decimal value
    int result = getDecimalValue(head);
    cout << "Decimal Value: " << result << "\n";
    
    return 0;
}