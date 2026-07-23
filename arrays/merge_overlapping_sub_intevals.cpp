#include<bits/stdc++.h>
using namespace std;



// brute force approach : 
vector<vector<int>> mergeoverlappingIntervals(vector<vector<int>> &arr){
    int n = arr.size(); 
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i<n;i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<= end ){
                end=max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
} 
// tc : O(N log N ) for sorting + O(2N) 
// sc : O(N)



// Optimal approach :
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
    int n = arr.size(); 
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i<n;i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(arr[i][1],ans.back()[1]);
        }
    }
    return ans;
}
// tc : O(N log n) + O(N)
// sc : O(N)



int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(2));
    
    cout << "Enter the intervals (start and end for each): \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    
    cout << "Merged Intervals: \n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}