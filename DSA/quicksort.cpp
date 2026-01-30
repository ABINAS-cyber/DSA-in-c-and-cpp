#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int p, int q) {
    int x = arr[q];   // pivot
    int i = p - 1;
    for (int j = p; j < q; j++) {
        if (arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[q]);
    return i + 1;  // return partition index
}

void quicksort(int arr[], int p, int q) {
    if (p < q) {
        int partitionIndex = partition(arr, p, q);
        quicksort(arr, p, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, q);
    }
}

int main() {
    cout << "Enter the size of array: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}