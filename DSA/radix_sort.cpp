#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxElement / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main() {
    vector<int> arr;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    radixSort(arr);
    cout << "Sorted array: ";
    for (int i : arr)
        cout << i << " ";
    cout << endl;
    return 0;
}