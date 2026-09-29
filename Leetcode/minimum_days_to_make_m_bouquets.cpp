#include<bits/stdc++.h>
using namespace std;


// brute force
bool possible(vector<int>& arr,int day,int m,int k){
    int cnt = 0;
    int n = arr.size();
    int noofB = 0;
    for(int i =0;i<n;i++){
        if(arr[i] <= day){
            cnt++;
        }else{
            noofB += (cnt/k);
            cnt=0;
        }
    }
    noofB += (cnt/k);
    if(noofB >= m) return true;
    else return false;
}

int minimumdaystomakembouquets(vector<int>& arr,int m,int k){
    int n= arr.size();
    if(n < m*k) return -1;
    for(int i =*min_element(arr.begin(),arr.end()) ;i<=*max_element(arr.begin(),arr.end());i++){
        if(possible(arr,i,m,k)) return i;
    }
    return -1;
}
// tc:O(max - min + 1) x (N)
// sc : O(1)






// optimal approach
bool Possible(vector<int>& arr,int day,int m,int k){
    int cnt = 0;
    int n = arr.size();
    int noofB = 0;
    for(int i =0;i<n;i++){
        if(arr[i] <= day){
            cnt++;
        }else{
            noofB += (cnt/k);
            cnt=0;
        }
    }
    noofB += (cnt/k);
    // if(noofB >= m) return true;
    // else return false;

    return noofB >= m;
}

int rosegarden(vector<int>& arr,int m,int k){
    long long val = m * 1LL * k * 1LL;
    if(val > arr.size()) return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i =0;i<arr.size();i++){
        mini = min(mini,arr[i]);
        maxi = max(maxi,arr[i]);
    }

    int low = mini, high = maxi;
    while(low <= high){
        int mid = (low + high)/2;
        if(Possible(arr,mid,m,k)) {
            high= mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}
// tc: O(log2(max - min + 1) x N)
// sc : O(1)





int main() {
    int n, m, k;
    cout << "Enter number of flowers: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter bloom days of flowers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of bouquets (m): ";
    cin >> m;
    cout << "Enter flowers per bouquet (k): ";
    cin >> k;

    // int result = minimumdaystomakembouquets(arr, m, k);
    int result = rosegarden(arr,m,k);
    if (result == -1) {
        cout << "It is not possible to make " << m << " bouquets." << endl;
    } else {
        cout << "Minimum days required: " << result << endl;
    }

    return 0;
}