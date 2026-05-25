//Q. Interchanging values in successive odd and successive even 
// position
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* createList(int n)
{
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter data for node " << i + 1 << ": ";
        int data;
        cin >> data;
        Node* newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void displayList(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


void oddeveninterchange(Node* head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = even;

    while (even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
}

int main(){
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    Node* head = createList(n);
    cout << "Original list: ";
    displayList(head);
    oddeveninterchange(head);
    cout << "List after interchanging odd and even positions: ";
    displayList(head);
    return 0;
}

