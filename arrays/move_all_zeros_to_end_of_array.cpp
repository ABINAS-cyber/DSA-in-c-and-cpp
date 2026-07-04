#include<bits/stdc++.h>
using namespace std;

// brute force approach
void moveZeroes(vector<int>& nums,int n) {
    // step - 1
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            temp.push_back(nums[i]);
        }
    }
    // step - 2
    int nz = temp.size();
    for(int i=0;i<nz;i++){
        nums[i] = temp[i];
    }
    // step - 3
    for(int i=nz;i<n;i++){
        nums[i] = 0;
    }
}



// optimal approach by tuf but without self comparision
vector<int> moveZeros2(vector<int> &nums , int n){
    int j=-1;
    for(int i = 0 ; i < n; i++){
        if(nums[i]==0){
            j=i;
            break;
        }
    }

    if(j == -1) return nums;

    for(int i = j+1;i<n;i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
    return nums;
}


// optimal approach but self comparision is done 
void moveZeroes3(vector<int>& nums,int n) {
    int j = 0;
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
} 



int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    // brute force approach
    // moveZeroes(nums,n);
    // for(int i=0;i<n;i++){
    //     cout<<nums[i]<<" ";
    // }


    // optimal approach
    moveZeros2(nums,n);
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}