#include<bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> arr){
    int maxi = 0;
    int cnt = 0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i]==1){
            cnt++;
            maxi=max(maxi,cnt);
        }else{
            cnt=0;
        }
    }
    return maxi;
}


int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<< "the maximum ones are : "<<findMaxConsecutiveOnes(arr);
    return 0;
}