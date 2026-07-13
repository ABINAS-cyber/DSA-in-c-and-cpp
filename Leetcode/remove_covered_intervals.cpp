#include<bits/stdc++.h>
using namespace std;


// ex : { [1,4],[2,8],[3,6]}
// ans : 2 


// approach 1 
int removecoveredintervals( vector<vector<int>> intervals){
    int n = intervals.size();
    vector<vector<int>>result;
    auto lambda = [](vector<int>&vec1,vector<int>&vec2){
        if(vec1[0] == vec2[0]){
            return vec1[1]>vec2[1];
        }
        return vec1[0]<vec2[0];
    };
    sort(intervals.begin(),intervals.end(),lambda);
    result.push_back(intervals[0]);
    for(int i =1;i<n;i++){
        if(result.back()[0] <=intervals[i][0] && result.back()[1] >= intervals[i][1]) continue;
        result.push_back(intervals[i]);
    }
    return result.size();
}


// approach 2
int Removecoveredintervals( vector<vector<int>> intervals){
    int n = intervals.size();
    vector<vector<int>>result;
    auto lambda = [](vector<int>&vec1,vector<int>&vec2){
        if(vec1[0] == vec2[0]){
            return vec1[1]>vec2[1];
        }
        return vec1[0]<vec2[0];
    };
    sort(intervals.begin(),intervals.end(),lambda);
    result.push_back(intervals[0]);
    for(int i =1;i<n;i++){
        if(result.back()[1] >= intervals[i][1]) continue;
        result.push_back(intervals[i]);
    }
    return result.size();
}

// approach 3
int RemoveCoveredIntervals( vector<vector<int>> intervals){
    int n = intervals.size();

    auto lambda = [](vector<int>&vec1,vector<int>&vec2){
        if(vec1[0] == vec2[0]){
            return vec1[1]>vec2[1];
        }
        return vec1[0]<vec2[0];
    };
    sort(intervals.begin(),intervals.end(),lambda);

    int lastintervalkaend = intervals[0][1];
    int cnt = 1;

    for(int i =1;i<n;i++){
        if(lastintervalkaend >= intervals[i][1]) continue;
        lastintervalkaend = intervals[i][1];
        cnt++;
    }
    return cnt;
}


int main(){
    int n ;
    cout<<"Enter the size of the element : ";
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(2));
    cout<<"Enter the elements : ";
    for(int i =0 ;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    cout <<"The fial size is remaining : "<<RemoveCoveredIntervals(arr);

    return 0;
}