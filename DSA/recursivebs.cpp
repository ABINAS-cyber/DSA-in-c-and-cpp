#include<bits/stdc++.h>
using namespace std;

int bs(int arr[], int x, int low, int high) {
    if (low > high) return -1;  // base case

    int mid = low + (high - low) / 2;

    if (arr[mid] == x) {
        return mid;  // return index, not value
    }
    else if (arr[mid] > x) {
        return bs(arr, x, low, mid - 1);
    }
    else {
        return bs(arr, x, mid + 1, high);
    }
}

int main() {
    cout << "Enter the size of array: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of array (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to search: ";
    int x;
    cin >> x;

    int result = bs(arr, x, 0, n - 1);
    if (result != -1)
        cout << "The element " << x << " is found at index " << result;
    else
        cout << "The element " << x << " is not found in the array.";
}