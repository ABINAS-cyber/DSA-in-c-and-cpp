#include<bits/stdc++.h> 
using namespace std;


int Uniquexortriplets2(vector<int> nums){
    int n = nums.size();

    // store all pair XOR
    unordered_set<int> s1;
    for(int i =0;i<n;i++){
        for(int j =i;j<n;j++){
            s1.insert(nums[i]^nums[j]);
        }
    }

    // find triplet XOR
    unordered_set<int> s2;
    for(int pairxor : s1){
        for(int &num : nums){
            s2.insert(pairxor ^ num);
        }
    }
    return s2.size();
}
// tc : O(n^2)
// sc : O(2 * maxel)



int uniquexortriplets2(vector<int> nums){
    int n =nums.size();
    int maxel = *max_element(begin(nums), end(nums));
    
    int T = 1;
    while (T <= maxel) {
        T *= 2; // T <<= 1;
    }
    
    vector<bool> S1(T, false); // XOR pair values set to true
    vector<bool> S2(T, false); // XOR triplet values set to true
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            S1[nums[i] ^ nums[j]] = true;
        }
    }
    
    for (int i = 0; i < T; i++) {
        if (S1[i] == true) {
            for (int num : nums) {
                S2[i ^ num] = true;
            }
        }
    }
    
    int count = 0; 
    for (int i = 0; i < T; i++) {
        if (S2[i] == true) {
            count++;
        }
    }
    
    return count;
}
// tc : O(n^2)
// sc : O(maxel)

int main(){
    int n ;
    cout<<"Enter the size : ";
    cin>>n;
    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The ans wer is : "<<uniquexortriplets2(arr);
    return 0;
}