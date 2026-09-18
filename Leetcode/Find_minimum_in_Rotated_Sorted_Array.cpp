#include<bits/stdc++.h>
using namespace std;

// brute : linear approach and find the minm


// better solun :
int findmin(vector<int>& arr){
    int low = 0 , high = arr.size() , ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[low] <= arr[mid]) {
            ans = min(ans,arr[low]);
            low = mid + 1;
        }
        else{
            high = mid - 1; 
            ans = min(ans,arr[high]);
        }
    }
    return ans;
}


// optimize it 
int Findmin(vector<int>& arr){
    int low = 0 , high = arr.size() , ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        // search space is already sorted
        // then always arr[low] will be smaller
        // in that search space
        if(arr[low] <= arr[high]){
            ans=min(ans,arr[low]);
            break;
        }
        if(arr[low] <= arr[mid]) {
            ans = min(ans,arr[low]);
            low = mid + 1;
        }
        else{
            high = mid - 1; 
            ans = min(ans,arr[high]);
        }
    }
    return ans;
}
// tc : O(log2(N)) unique 


// duplicate 
int FindMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = (low + high) / 2;

        // If the subarray is already sorted
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        // Handle duplicates: shrink search space
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            ans = min(ans, arr[low]);
            low++;
            high--;
            continue;
        }

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // Right half is sorted
        else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}




int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements of rotated sorted array:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Minimum element: " << FindMin(arr) << endl;
    return 0;
}