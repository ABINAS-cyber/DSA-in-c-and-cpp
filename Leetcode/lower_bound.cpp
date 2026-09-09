#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int>&arr,int target){
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


// recursive
int Lowerbound(vector<int> &arr, int low, int high, int target) {
    int n = arr.size();
    if (low > high) return n; // base case

    int mid = (low + high) / 2;

    if (arr[mid] >= target) {
        // candidate found, but check left side for earlier occurrence
        int leftAns = Lowerbound(arr, low, mid - 1, target);
        return min(mid, leftAns);
    } else {
        // search in right half
        return Lowerbound(arr, mid + 1, high, target);
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

    // iterative 
    // int idx = lowerbound(arr, x);

    // recursive 
    int idx = Lowerbound(arr,0,n-1,x);

    if (idx == n) {
        cout << "No element is greater than or equal to " << x << endl;
    } else {
        cout << "Lower bound index: " << idx << endl;
        cout << "Element at lower bound: " << arr[idx] << endl;
    }

    return 0;
}