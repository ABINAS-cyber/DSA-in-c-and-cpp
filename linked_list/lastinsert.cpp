/*while (temp != NULL)  
Iterates through every node, including the last one. That’s why you see the last node’s data printed before NULL.

while (temp->next != NULL)  
Stops one step earlier, because when temp points to the last node, its next is NULL. The loop ends before printing the last node’s data.
In other words, the final node will be skipped.

👉 Example:
Suppose the list is 10 -> 20 -> 30 -> NULL.

With while (temp != NULL) → Output: 10 -> 20 -> 30 -> NULL

With while (temp->next != NULL) → Output: 10 -> 20 -> (and then it stops, missing 30)

So, if your goal is to display the entire linked list including the last node, you should stick with while (temp != NULL).
If you specifically want to stop before the last node (say, for operations like inserting something before the tail), then while (temp->next != NULL) makes sense.
*/

#include<bits/stdc++.h>

using namespace std ;

struct Node
{
     int data ;
     Node* next;
};

Node* head =NULL , * tail = NULL;

void creation(){
    Node* newnode = new Node;
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
    Node* temp = head;
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    if(temp->next==NULL){
        cout<<temp->data<<"->NULL"<<endl;
    }
}

void lastinsert(){
    Node* newnode = new Node;
    Node *temp;
    cout<<"Enter the data to enter into last node: ";
    int item;
    cin>>item;
    if(newnode==NULL){
        cout<<"overflow";
    }
    else{
        newnode->data = item;
        if(head == NULL){
            newnode->next = NULL;
            head = newnode;
            cout<<"Node inserted at last"<<endl;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
            cout<<"Node inserted at last"<<endl;
        }
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
    lastinsert();
    display();
    return 0;
}