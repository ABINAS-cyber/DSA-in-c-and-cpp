#include<bits/stdc++.h>
using namespace std;

// ex :  { 2,2,3,3,1,2,2}

// Brute force approach 
int majority_element(vector<int> arr ){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]) cnt++;
        }
        if(cnt > n/2) return arr[i];
    }
}

// tc - big-oh(n^2)



// better approach
int Majority_element(vector<int> arr){
    map<int,int> mpp;
    // N log N
    for(int i=0 ;i<arr.size();i++){
        mpp[arr[i]]++;
    }
    // O(N)
    for(auto it: mpp){
        if(it.second  > (arr.size()/2)){
            return it.first;
        }
    }
    return -1;
}

// tc : O(N log N) + O(N)
// sc : O(N) -> if array contains only unique elements



// optimal approach 
// Moore's Voting Algorithm 
int Majority_Element(vector<int> arr){
    int cnt=0;
    int el;
    for(int i=0;i<arr.size();i++){
        if(cnt==0) {
            cnt = 1;
            el=arr[i];
        }
        else if(arr[i] == el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == el) cnt1++;
    }
    if(cnt1 > (arr.size()/2)){
        return el;
    }
    return -1;
}
// tc : O(N) + O(N)
// sc : O(1)


int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"Enter the elements : ";
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    cout<<"The major element is  : "<<Majority_element(arr);
    return 0;
}