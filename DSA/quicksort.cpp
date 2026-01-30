#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int p, int q,int pivot_index) {
    if(pivot_index<p || pivot_index>q){
        pivot_index=q;
    }
    swap(arr[pivot_index], arr[q]);
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

void quicksort(int arr[], int p, int q,int pivot_index) {
    if (p < q) {
        int partitionIndex = partition(arr, p, q,pivot_index);
        quicksort(arr, p, partitionIndex - 1,pivot_index);
        quicksort(arr, partitionIndex + 1, q,pivot_index);
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

    cout<<"enter the pivot index:";
    int pivot_index;
    cin>>pivot_index;
    quicksort(arr, 0, n - 1,pivot_index);

    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}