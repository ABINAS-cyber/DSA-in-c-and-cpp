#include<bits/stdc++.h>
using namespace std;

// brute-force approach 
vector<vector<int>> foursum(vector<int> arr,int target){
    int n = arr.size();
    set<vector<int>> st;
    for(int i = 0 ; i <n;i++){
        for(int j = i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l = k+1;l<n;l++){
                    long long sum = arr[i] + arr[j];
                    sum+=arr[k];
                    sum+=arr[l];
                    if(sum == target){
                        vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// tc : O(N^4)
// sc : O(no of quads) x 2



// better solution
vector<vector<int>> Foursum(vector<int> arr, int target){
    int n = arr.size();
    set<vector<int>> st;
    for(int i =0;i<n;i++){
        for(int j=i+1; j<n;j++){
            set<long long> hashset;
            for(int k =j+1;k<n;k++){
                long long sum = arr[i] + arr[j];
                sum+=arr[k];
                long long fourth = target - (sum);
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp = {arr[i],arr[j],arr[k],(int)fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
// tc : O(N^3) * O(log number of element in the set)
// sc : O(N) + O(quads) x 2


// optimal appraoch 
vector<vector<int>> FourSum(vector<int> arr, int target){
    int n = arr.size();
    vector<vector<int>> ans ;
    sort(arr.begin(),arr.end());
    for(int i =0;i<n;i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        for(int j = i+1;j<n;j++){
            if(j != (i+1) && arr[j] == arr[j-1]) continue;
            int k = j+1;
            int l =n-1;
            while(k<l){
                long long sum = arr[i]+arr[j];
                sum+=arr[k];
                sum+=arr[l];
                if(sum == target){
                    vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k++ ; l--;
                    while(k<l && arr[k] == arr[k-1]) k++;
                    while(k<l && arr[l] == arr[l+1]) l--;
                }
                else if(sum < target) k++;
                else l--;
            }
        }
    }
    return ans;
}
// tc : O(n^3) 
// sc : O(no . of quads)

int main(){
    int n ;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"Enter the target value : ";
    int target;
    cin>>target;
    vector<int> arr(n);
    cout<<"Enter the elements : "<<endl;
    for(int  i =0 ;i<n;i++){
        cin>>arr[i];
    }

    vector<vector<int>>aree = FourSum(arr,target); 
    for(auto it : aree){
        cout << "[ ";
        for(auto num : it){
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}