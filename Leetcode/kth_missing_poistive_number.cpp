#include<bits/stdc++.h>
using namespace std;

// brute approach
int missingk(vector<int>& arr,int k){
    int n  = arr.size();
    for(int i =0 ;i<n;i++){
        if(arr[i] <= k) k++;
        else break;
    }
    return k;
}
// tc : O(N)
// sc : O(1)


// optimal approach
int MissingK(vector<int> arr,int k){
    int n = arr.size();
    int low = 0 , high = n - 1;
    while(low <= high){
        int mid = (low + high)/2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k) low = mid + 1;
        else high = mid - 1;
    }
    return low + k;
}
// tc : O(log(N))
// sc : O(1)




int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter k: ";
    cin >> k;

    int result = MissingK(arr, k);
    cout << "The k-th missing number is: " << result << endl;

    return 0;
}