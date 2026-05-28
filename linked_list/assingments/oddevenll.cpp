#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node *creationlist(int n){
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


Node* oddEvenList(Node* head) {
    // If the list is empty or has only one node, return it as is
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Initialize pointers
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even; // Keep track of the start of the even list

    // Traverse and rearrange
    while (even != NULL && even->next != NULL) {
        odd->next = even->next;       // Connect odd to the next odd node
        odd = odd->next;              // Move odd pointer forward
        
        even->next = odd->next;       // Connect even to the next even node
        even = even->next;            // Move even pointer forward
    }

    // Connect the end of the odd list to the head of the even list
    odd->next = evenHead;

    return head;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // 1. Create the list
    Node* head = creationlist(n);

    // 2. Display the original list
    cout << "\nOriginal List: \n";
    display(head);

    // 3. Rearrange the list
    head = oddEvenList(head);

    // 4. Display the modified list
    cout << "\nOdd Even Linked List: \n";
    display(head);

    return 0;
}