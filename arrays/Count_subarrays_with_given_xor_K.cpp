#include<bits/stdc++.h>
using namespace std;

int subarrayswithsumk(vector<int> arr, int k){
    int xr = 0;
    map<int,int> mpp;
    mpp[xr]++; // {0,1}
    int cnt = 0 ;
    for(int i =0 ;i<arr.size();i++){
        xr = xr ^ arr[i];
        // k
        int x = xr ^ k;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}


int main(){
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the k value : ";
    cin>>k;
    cout << "The no.s of subarrays are : "<<subarrayswithsumk(arr,k);
    return 0;
}