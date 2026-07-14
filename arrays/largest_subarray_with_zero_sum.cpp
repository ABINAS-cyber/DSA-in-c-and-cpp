#include<bits/stdc++.h>
using namespace std;


// ex : [1 -1 3 2 -2 -8 1 7 10 23]
// ans : 5 

int maxlen(vector<int> arr){
    int n = arr.size();

    unordered_map<int,int> mpp;
    int maxi = 0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            maxi=i+1;
        }
        else{
            if(mpp.find(sum) != mpp.end()){
                 maxi=max(maxi,i-mpp[sum]);
            }
            else{
                mpp[sum] = i;  
            }
        }
    }
    return maxi;
}

int main(){
    int n;
    cout<<"Enter the size : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element : ";
    for(int i =0;i <n;i++){
        cin>>arr[i];
    }
    cout<<"The length is : "<<maxlen(arr);
    return 0;
}