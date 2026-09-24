#include<bits/stdc++.h>
using namespace std;


bool search(vector<int> &arr,int target){
    int low = 0 , high = arr.size() - 1;
    while(low <= high){
        int mid = (low + high) /2;
        if(target ==  arr[mid]) return true;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++ , high--;
            continue;
        }

        if(arr[low] <= arr[mid]){
            if(target >= arr[low] && target < arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(target > arr[mid] && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    } 
    return false;
}
// tc: O(log2(N)) average  or worst case : O(N/2)
// sc : O(1)

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements (rotated sorted array with possible duplicates): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target element: ";
    cin >> target;

    if (search(arr, target)) {
        cout << "Element found!" << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}