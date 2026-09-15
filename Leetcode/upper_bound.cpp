#include<bits/stdc++.h>
using namespace std;

int upperbound(vector<int>&arr,int target){
    int n = arr.size();
    int low = 0 , high = n-1;
    int ans=n;
    while(low <= high){
        int mid = ( low + high ) / 2;
        if(arr[mid] > target){
            ans = mid;
            high  = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;    
}



// recursive
int Upperbound(vector<int>&arr,int low,int high , int target){
    int n = arr.size();
    if (low > high) return n; // base case

    int mid = (low + high) / 2;

    if (arr[mid] > target) {
        // candidate found, but check left side for earlier occurrence
        int leftAns = Upperbound(arr, low, mid - 1, target);
        return min(mid, leftAns);
    } else {
        // search in right half
        return Upperbound(arr, mid + 1, high, target);
    }
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

    int idxIter = upperbound(arr, x);
    int idxRec = Upperbound(arr, 0, n - 1, x);

    cout << "\nIterative upper bound index: " << idxIter;
    if (idxIter != n) cout << " (element = " << arr[idxIter] << ")";
    else cout << " (no element greater than " << x << ")";

    cout << "\nRecursive upper bound index: " << idxRec;
    if (idxRec != n) cout << " (element = " << arr[idxRec] << ")";
    else cout << " (no element greater than " << x << ")";

    cout << endl;
    return 0;
}