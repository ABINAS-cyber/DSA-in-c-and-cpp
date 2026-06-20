#include<bits/stdc++.h>
using namespace std;

int buy_and_sell_stock(vector<int> arr) {
    int n = arr.size(); 
    int mini=arr[0];
    int maxprofit = 0;
    for(int i=0 ; i < n;i++){
        int cost = arr[i] - mini;
        maxprofit = max(maxprofit,cost);
        mini = min(mini,arr[i]);
    }
    return maxprofit;
}
// tc : O(N)
// sc : O(1)
// This is a dp becoz we are remembering the past 


int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"Enter the element : \n";
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The maximum profit is : "<<buy_and_sell_stock(arr);
    return 0;
}