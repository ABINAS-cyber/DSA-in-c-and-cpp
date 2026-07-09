#include<bits/stdc++.h>
using namespace std;

// {1,1,2,3,3,8,8}


// brute force approach
int appearing_once(int arr[],int n){
    for(int i =0;i<n;i++){
        int num=arr[i];
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]==num){
                cnt++;
            }
        }
        if(cnt==1) return num;
    }
}


// better approach
int appears_once(int arr[],int n){
    int maxi = arr[0];
    for(int i =0 ;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    int hash[maxi+1]={0};
    for(int i=0 ;i<n;i++){
        hash[arr[i]]++;
    }
    for(int i =0;i<n;i++){
        if(hash[arr[i]]==1){
            return arr[i];
        }
    }
}


// better approach without using hash if it is bigger like 10^9 or 10^12
// or negative number which is probably yes and no 
// that when you have to use the map datastuctures with a bigger datatype as key
int appear_one(int arr[],int n){

    map<long long ,int> mpp;

    for(int i =0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto it : mpp){
        if(it.second == 1) return it.first;
    }
}


// optimal approach
int appear_once(int arr[],int n){
    int xorr = 0;
    for(int i=0;i<n;i++){
        xorr=xorr ^ arr[i];
    }
    return xorr;
}




int main(){
    int n;
    cout<<"Enter the size of the array :"<<endl;
    cin>>n;
    cout<<" Enter the element :";
    int arr[n];
    for(int i = 0 ; i<n;i++){
        cin>>arr[i];
    }
    cout<<appear_once(arr,n);
    return 0;
}