#include<bits/stdc++.h>

using namespace std;

struct Node {
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

void printCodes(Node* root, string str) {
    if (!root) return;

    if (root->data != '$') {
        cout << root->data << ": " << str << endl;
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void huffmanCodes(char data[], int freq[], int n) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < n; i++) {
        minHeap.push(new Node(data[i], freq[i]));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* internalNode = new Node('$', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    printCodes(minHeap.top(), "");
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {45, 13, 12, 16, 9, 5};
    int n = sizeof(data) / sizeof(data[0]);

    huffmanCodes(data, freq, n);

    return 0;
}