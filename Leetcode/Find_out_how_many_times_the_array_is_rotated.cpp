#include<bits/stdc++.h>
using namespace std;



int findKRotation(vector<int>& arr){
    int low = 0 , high = arr.size() - 1 , ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then always arr[low] will be smaller
        // in that search space
        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            break;
        }
        if(arr[low] <= arr[mid]) {
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }
        else{
            high = mid - 1; 
            if(arr[mid] < ans){
                index = mid;
                ans = arr[low];
            }
        }
    }
    return index;
}



// duplicates

int findKrotation(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // If the current segment is sorted
        if (arr[low] < arr[high]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            break;
        }

        // Handle duplicates
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            low++;
            high--;
            continue;
        }

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] < ans) {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        // Right half is sorted
        else {
            if (arr[mid] < ans) {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}



int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements (rotated sorted array): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int rotationIndex = findKrotation(arr);
    cout << "Array is rotated " << rotationIndex << " times.\n";
    return 0;
}