#include<bits/stdc++.h>
using namespace std;

// brute force approach 
vector<vector<int>> threesum(vector<int> arr){
    int n = arr.size();
    set<vector<int>> st;
    for(int i = 0 ;i<n;i++){
        for(int j = i+1 ; j<n;j++){
            for(int k = j + 1;k<n;k++){
                if(arr[i]+arr[j]+arr[k] == 0){
                    vector<int> temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// tc : O(N^3)*log(no . of unique triplets)
// sc : 2 * O(no . of triplets)


// better approach
vector<vector<int>> triplet(vector<int> arr){
    set<vector<int>> st;
    int n = arr.size();
    for (int  i = 0; i < n; i++)
    {
        set<int> hashmap;
        for (int  j = i; j < n; j++)
        {
            int third = -(arr[i]+arr[j]);
            if(hashmap.find(third) != hashmap.end()){
                vector<int> temp = {arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashmap.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// tc : O(N^2) * O(log(m))
// m : size of the set
// sc : O(N) + O(no . of unique triplet)

 

// optimal approach 
vector<vector<int>> Triplet(vector<int> arr){
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i =0 ;i<n;i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        int j  = i+1;
        int k = n-1;
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0){
                j++;
            }
            else if(sum  > 0 ){
                k--;
            }
            else{
                vector<int> temp = {arr[i],arr[j],arr[k]};
                ans.push_back(temp);
                k--;
                j++;
                while (j<k && arr[j]==arr[j-1]) j++;
                while (j<k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}
// tc : O(N log N) to sort + O(N) external n loop  + while loop is runnig for O(N x n)  
// sc : O(no . of unique triplets)



int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // vector<vector<int>>aree = threesum(arr); 
    vector<vector<int>>aree = Triplet(arr); 
    for(auto it : aree){
        cout << "[ ";
        for(auto num : it){
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}