#include<bits/stdc++.h>
using namespace std;


// Brute force approach 
int maximum_subarray_sum(vector<int> arr){
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j = i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            maxi=max(sum,maxi);
        }
    }
    return maxi;
}
// tc : O(n^3)
// sc : O(1)


// better approach 
int Maximum_subarray_sum(vector<int> arr){
    int n = arr.size();
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j = i;j<n;j++){
            sum += arr[j];
            maxi=max(sum,maxi);
        }
    }
    return maxi;
}
// tc : O(n^2)
// sc : O(1)


// optimal approach 
// most optimal approach we will be using kadane's algorithm
long long maxSubarray(int arr[] , int n){
    long long sum = 0 ,maxi = LONG_MIN;
    for(int i=0;i<n;i++){
        sum +=arr[i];

        if(sum > maxi){
            maxi=sum;
        }

        if(sum < 0) {
            sum = 0;
        }

        if(maxi < 0) return 0;
    }
    return maxi;
}
// tc : O(n)
// sc : O(1)



// can you print the subarray with the maximum sum
long long MaxSubarray(int arr[] , int n){
    long long sum = 0 ,maxi = LONG_MIN;
    for(int i=0;i<n;i++){
        int ansstart=-1 , ansend=-1;
        int start;
        if(sum==0) start = i;
        sum +=arr[i];

        if(sum > maxi){
            maxi=sum;
            ansstart = start , ansend = i;
        }

        if(sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}

// tc : O(n)
// sc : O(1)



int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element : ";
    for(int i = 0 ; i<n;i++){
        cin>>arr[i];
    }
    cout<<"the sum of the maximumu subarray is : "<< maximum_subarray_sum(arr);
    return 0;
}