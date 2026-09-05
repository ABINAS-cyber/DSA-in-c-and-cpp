#include<bits/stdc++.h>
using namespace std;

// brute force
int firststableindex(vector<int>& nums,int k){
    int n = nums.size();
    for(int i =0 ;i<n;i++){
        int maxel = INT_MIN;
        int minel = INT_MAX;
        for(int j = 0 ;j<=i;j++){
            maxel = max(maxel,nums[j]);
        }
        for(int j = i ; j<n;j++){
            minel = min(minel,nums[j]);
        }
        if(maxel - minel <= k){
            return i;
        }
    }
    return -1;
}
// tc: O(N^2)
// sc:O(1)


// optimal approach 
int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int minel = INT_MAX;
        vector<int>minfromindex(n);
        // pre process
        for(int i = n - 1;i>=0;i--){
            minel = min(minel,nums[i]);
            minfromindex[i]=minel;
        } 

        int maxel = INT_MIN;

        for(int i = 0;i<n;i++){
            maxel = max(maxel,nums[i]);
            minel = minfromindex[i];
            if(maxel - minel <= k){
                return i ;
            }
        }
        return -1;
    }
// tc: O(N)
// sc:O(N)


int main(){
    int size;
    cout<<"Enter the size of the array : ";
    cin>>size;

    vector<int> arr(size);
    cout<<"Enter the elements for array : ";
    for (int i = 0; i < size; i++){
        cin>>arr[i];
    }
    
    int k;
    cout<<"Enter the k value : ";
    cin>>k;
    
    // int ans = firststableindex(arr,k);
    int ans = firstStableIndex(arr,k);
    cout<<"First stable index: "<<ans<<endl;

    return 0;
}