#include<bits/stdc++.h>
using namespace std;

int IBinarysearch(vector<int>&arr,int target){
    int n = arr.size();
    int low = 0, high = n-1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if(target == arr[mid]) return mid;
        else if (target > arr[mid]) low = mid + 1;
        else high = mid - 1 ;
    }
    return -1;
}


int RBinarysearch(vector<int>&arr,int low ,int high,int target){
    if(low  > high) return -1;
    int mid = (low + high)/2;
    if(arr[mid] == target) return mid;
    else if (target > arr[mid]) return RBinarysearch(arr,mid + 1,high,target);
    else RBinarysearch(arr,low,mid - 1,target); 
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target element: ";
    cin >> target;

    // int result = IBinarysearch(arr, target);
    int result = RBinarysearch(arr,0,n-1,target);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}