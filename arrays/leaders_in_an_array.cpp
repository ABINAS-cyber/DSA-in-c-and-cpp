#include<bits/stdc++.h>
using namespace std;


// brute force approach most naive extreme approach is 
vector<int> leaders_in_aray(vector<int> arr){
    vector<int> ans;
    int n = arr.size();
    for(int i=0;i<n;i++){
        bool leader = true ;
        for(int j =i+1;j<n;j++){
            if(arr[j]>arr[i]) {
                leader = false;
                break;
            }
        }
        if(leader ==  true) ans.push_back(arr[i]);
    }
    return ans;
}
// tc : O(n^2)
// sc : O(n)



// optimal approach
vector<int> Leaders_in_array(vector<int> arr){
    // O(N)
    vector<int> ans;
    int n = arr.size();
    int maxi = INT_MIN;
    // O(N)
    for(int i = n-1 ; i>=0 ;i--){
        if(arr[i]>maxi){
            // maxi=arr[i];
            ans.push_back(arr[i]);
        }
        // keep track of right max
        maxi=max(maxi,arr[i]);
    }
    // O(N log N)
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // arr = leaders_in_aray(arr);
    arr = Leaders_in_array(arr);
    for(auto it : arr){
        cout<<it<<" ";
    }
    return 0;
}