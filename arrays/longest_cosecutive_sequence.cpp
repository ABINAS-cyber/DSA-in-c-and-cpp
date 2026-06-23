#include<bits/stdc++.h>
using namespace std;


// most naive approach 
// brute force approach 
bool ls(vector<int> arr,int num){
    int n= arr.size();
    for(int i=0;i<n;i++){
        if(arr[i] == num ){
            return true;
        }
    }
    return false;
}

int longest_consecutive_sequence(vector<int> arr){
    int n = arr.size();
    int longest = 1;
    for(int i=0;i<n;i++){
        int x = arr[i];
        int cnt = 1;
        while(ls(arr,x+1)){
            x+=1;
            cnt+=1;
        }
        longest = max(longest,cnt);
    }
    return longest;
}
// tc : O(N) x O(N) nearly O(N^2)
// sc: O(1)


// better approach 
int Longest_consecutive_sequence(vector<int> arr){
    int n = arr.size();
    if(n == 0) return 0;
    sort(arr.begin(),arr.end());
    // O(N log N)
    int longest = 1;
    int cntcurr = 0;
    int lastsmaller = INT_MIN;
    // O(N)
    for(int i=0;i<n;i++){
        if(arr[i]-1==lastsmaller){
            cntcurr+=1;
            lastsmaller=arr[i];
        }
        else if(arr[i] != lastsmaller){
            cntcurr=1;
            lastsmaller=arr[i];
        }
        longest = max(longest,cntcurr);
    }
    return longest;
}
// tc : O(N)+O(N log N)
// sc : O(1)




// optimal approach 
int Longest_Consecutive_Sequence(vector<int> arr){
    int n = arr.size();
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st ;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it : st ){
        if(st.find(it - 1) == st.end()){
            int cnt=1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x+=1;
                cnt+=1;
            }
            longest = max(longest,cnt);
        }
    }
    return longest;
}
// tc if we take unordered_set : O(1) for best and average case 
// for worst case when collisions happens:O(N)
// tc : O(2N)
// in worst case O(3N)
// sc : O(N)

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements : ";
    for(int i = 0 ;i<n;i++ ){
        cin>>arr[i];
    }
    cout<<"The longest consecutive sequence is : "<<Longest_Consecutive_Sequence(arr);
    return 0;
}