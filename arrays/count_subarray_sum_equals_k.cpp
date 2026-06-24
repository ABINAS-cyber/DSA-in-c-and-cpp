#include<bits/stdc++.h>
using namespace std;

// brute force approach
int count_subarray_sum_equal_k(vector<int> arr,int kth){
    int n = arr.size();
    int cnt =0;
    for(int i = 0 ;i<n;i++){
        for(int j =i ;j<n;j++){
            int sum = 0;
            for(int k =i ;k<=j;k++){
                sum+=arr[k];
            }
            if(sum==kth){
                cnt++;
            }
        }
    } 
    return cnt;
}





// better approach 
int count_Subarray_sum_equal_k(vector<int> arr,int kth){
    int n = arr.size();
    int cnt =0;
    for(int i = 0 ;i<n;i++){
        int sum = 0;
        for(int j =i ;j<n;j++){
            sum+=arr[j];
            if(sum==kth){
                cnt++;
            }
        }
    } 
    return cnt;
}


// most optimal approach
int findallsubarraywithgivensum(vector<int> arr,int k){
    map<int,int> mpp;
    mpp[0]=1;
    int presum = 0 , cnt = 0;
    for(int i=0;i<arr.size();i++){
        presum+=arr[i];
        int remove = presum - k;
        cnt += mpp[remove];
        mpp[presum] += 1; 
    }

    return cnt;
}
// tc : O(N x log N)
// sc : O(N)




int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element : "<<"\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k ;
    cout<<"Enter the sum(k) : ";
    cin>>k;
    cout<<"The count of subarray sum equal k is : "<<findallsubarraywithgivensum(arr,k);
}