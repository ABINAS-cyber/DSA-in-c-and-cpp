#include<bits/stdc++.h>
using namespace std;

int uniqueXORtriplets(vector<int> &nums){
    int n = nums.size();
    if(n <= 2){
        return n;
    }
    int ans = 1;
    while (ans <= n)
    {
        ans<<= 1;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size :";
    cin>>n;
    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"the ans is : "<<uniqueXORtriplets(arr) ;
    return 0;
}