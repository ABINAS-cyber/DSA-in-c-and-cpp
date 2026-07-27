#include<bits/stdc++.h>
using namespace std;


int maximumproduct(vector<int>& nums){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    int ans = max(nums[n-1]*nums[n-2]*nums[n-3],nums[0]*nums[1]*nums[n-1]);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size : ";
    cin>>n;

    if (n < 3) {
        cout << "Array must contain at least 3 elements." << endl;
        return 0;
    }

   vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Call the function and print the result
    cout << "Maximum product: " << maximumproduct(arr) << endl;
    
    return 0;
}