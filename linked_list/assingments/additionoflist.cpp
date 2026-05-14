#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
};  // no constructors


// Helper function to create a linked list from user input
ListNode* createList(int n) {
    if (n <= 0) return nullptr;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int data;
        cout << "Enter digit " << i+1 << ": ";
        cin >> data;
        ListNode* newnode = new ListNode; // allocate node
        newnode->val = data;              // assign value manually
        newnode->next = nullptr;          // set next pointer
        if (!head) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    return head;
}


// Helper function to display a linked list
void display(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}


// Solution class for Add Two Numbers
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode;
        dummy->val = 0;
        dummy->next = nullptr;
        ListNode* temp = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            ListNode* newnode = new ListNode;
            newnode->val = sum % 10;
            newnode->next = nullptr;
            temp->next = newnode;
            temp = temp->next;
        }
        return dummy->next;
    }
};


int main() {
    int n1, n2;
    cout << "Enter number of digits in first list: ";
    cin >> n1;
    ListNode* l1 = createList(n1);

    cout << "Enter number of digits in second list: ";
    cin >> n2;
    ListNode* l2 = createList(n2);

    cout << "First number list: ";
    display(l1);
    cout << "Second number list: ";
    display(l2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Sum list: ";
    display(result);

    return 0;
}
