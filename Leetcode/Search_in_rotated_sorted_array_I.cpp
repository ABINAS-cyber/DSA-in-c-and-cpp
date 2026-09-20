#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &arr,int target){
    int low = 0 , high = arr.size() - 1;
    while(low <= high){
        int mid = (low + high) /2;
        if(target ==  arr[mid]){
            return mid;
        }

        if(arr[low] <= arr[mid]){
            if(target >= arr[low] && target <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(target >= arr[low] && target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
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

    int target;
    cout << "Enter target element: ";
    cin >> target;

    int result = search(arr, target);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}