#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void maxheapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i;     // left child
    int r = 2*i + 1; // right child

    if (l <= n && arr[l] > arr[largest])
        largest = l;

    if (r <= n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxheapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2; i >= 1; i--) {
        maxheapify(arr, n, i);
    }
}

void heapsort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n; i >= 2; i--) {
        swap(arr[1], arr[i]);       // move max to end
        maxheapify(arr, i-1, 1);    // heapify reduced heap
    }
}

int main() {
    cout << "Enter the size of array: ";
    int n;
    cin >> n;

    int arr[n+1]; // +1 for 1-based indexing

    cout << "Enter the elements of array: ";
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    heapsort(arr, n);

    cout << "Sorted array is: ";
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}