#include<bits/stdc++.h>
using namespace std;


int floor(vector<int>&arr,int target){
    int ans =-1;
    int n = arr.size();
    int low = 0 , high = n - 1;
    while (low <= high){
        int mid = (low + high)/2;
        if(arr[mid] <= target){
            ans = arr[mid];
            low = mid + 1;
        }   
        else high = mid - 1;
    }
    return ans;
}


int ceil(vector<int>&arr,int target){
    int n = arr.size();
    int ans = -1;
    int low = 0 , high = n-1;
    while (low <= high)
    {
        int mid = (low + high) /2;
        if(arr[mid] >= target){
            ans = arr[mid];
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}




int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the value of x: ";
    cin >> x;

    int fl = floor(arr, x);
    int cl = ceil(arr, x);

    if (fl == -1)
        cout << "Floor does not exist for " << x << endl;
    else
        cout << "Floor of " << x << " is " << fl << endl;

    if (cl == -1)
        cout << "Ceil does not exist for " << x << endl;
    else
        cout << "Ceil of " << x << " is " << cl << endl;

    return 0;
}