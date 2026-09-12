#include<bits/stdc++.h>
using namespace std;

int searchinsertposition(vector<int>&arr,int target){
    int n = arr.size();
    int low = 0 , high = n-1;
    int ans=n;
    while(low <= high){
        int mid = ( low + high ) / 2;
        if(arr[mid] >= target){
            ans = mid;
            high  = mid - 1;
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
    cout << "Enter the target value: ";
    cin >> x;

    int idx = searchinsertposition(arr, x);

    cout << "Insert position for " << x << " is index " << idx;
    if (idx < n) cout << " (element at that position = " << arr[idx] << ")";
    else cout << " (insert at end)";
    cout << endl;

    return 0;
}