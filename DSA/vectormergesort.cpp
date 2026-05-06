#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    int i=0 , j = 0 ,  k=p;
    for(; i < n1 && j < n2; k++) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
    }
    while (i<n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &arr, int p, int r) {
    if(p < r) {
        int m = p + (r - p) / 2;
        mergesort(arr, p, m);
        mergesort(arr, m + 1, r);
        merge(arr, p, m, r);
    }
}

int main() {
    cout <<"Enter the size of array: ";
    int n;
    cin >> n;
    vector<int> arr(n);
    cout <<"Enter the elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);
    cout <<"Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}