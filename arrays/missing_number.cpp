#include<bits/stdc++.h>
using namespace std;

// brute force approach
int missingnumber(int arr[],int n){
    for(int i =1 ;i<=n;i++){
        int flag = 0;
        for(int j = 0 ; j<n-1;j++){
            if(arr[j] == i){
                flag=1;
                break;
            }
        }
        if(flag==0) return i;
    }
}


// better approach
int missing_number(int arr[],int n){
    int hash[n+1]={0};
    for(int i =0 ;i<n-1;i++){
        hash[arr[i]]=1;
    }
    for(int i=1 ;i<n;i++){
        if(hash[i] == 0) return i;
    }
}


// optimal approach solutions :
// 1> sum
// 2> XOR

// 1> sum
int missing_num(int arr[],int n){
    int sum = n*(n+1)/2;
    int sum2 =0;
    for(int i=0;i<n-1;i++){
        sum2+=arr[i];
    }
    return sum-sum2;
}

// 2> XOR TC: big-oh(2N)
int missing_no(int arr[],int n){
    int XOR1=0;
    for(int i =1;i<n;i++){
        XOR1 = XOR1 ^ i;
    }

    int XOR2=0;
    for(int i =1;i<n-1;i++){
        XOR2 = XOR2 ^ i;
    }
    return XOR1 ^ XOR2;
}


// 2> XOR  TC: big-oh(N)
int MissingNumber(int arr[],int N){
    int n = N-1;
    int xor1=0 , xor2=0;
    for(int i=0 ;i<n;i++){
        xor2=xor2 ^ arr[i];
        xor1=xor1 ^ (i+1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}





int main(){
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The missing number is :  "<<MissingNumber(arr,n);
    return 0;
}