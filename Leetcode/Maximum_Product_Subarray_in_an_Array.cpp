#include<bits/stdc++.h>
using namespace std;

// brute solutions
int Subarraywithmaxproduct(vector<int> &arr){
    int maxm = INT_MIN;
    int n = arr.size();
    for(int i =0;i<n;i++){
        for(int j = i ;j<n;j++){
            int prod =1;
            for(int k =i ;k<=j;k++){
                prod *= arr[k];
            }
            maxm = max(maxm,prod);
        }
    }
    return maxm;
}
//tc : O(N^3)
// sc : O(1)



// better approach 
int SubarraywithMaxproduct(vector<int> &arr){
    int maxm = INT_MIN;
    int n = arr.size();
    for(int i =0;i<n;i++){
        int prod = 1;
        for(int j = i ;j<n;j++){
            prod *= arr[j];
            maxm = max(maxm,prod);
        }
    }
    return maxm;
}

//tc : O(N^2)
// sc : O(1)



// optimal solutions 1 
int subarraywithmaxproduct(vector<int> &arr){
    int pre = 1 , suff = 1;
    int n = arr.size();
    int maxm = INT_MIN;
    for(int i =0 ;i<n;i++){
        if(pre == 0 ) pre = 1;
        if(suff == 0 ) suff = 1;
        pre  *=  arr[i];
        suff *=  arr[n - i - 1];
        maxm=max(maxm,max(pre,suff));
    }
    return maxm;
}
//tc : O(N)
// sc : O(1)



int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the elements : ";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The subarray with max product : "<<Subarraywithmaxproduct(arr)<<endl;
    cout<<"The subarray with max product : "<<SubarraywithMaxproduct(arr)<<endl;
    cout<<"The subarray with max product : "<<subarraywithmaxproduct(arr)<<endl;
    return 0;
}