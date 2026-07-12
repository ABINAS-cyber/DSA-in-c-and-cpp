#include<bits/stdc++.h>
using namespace std;

vector<int> arrayRankTransform(vector<int> &arr){
    int n= arr.size();
    vector<pair<int,int>> temp;
    for(int i=0;i<n;i++){
        temp.push_back({arr[i],i});
    }
    sort(temp.begin(),temp.end());
    int rank =1;
    vector<int>ans(n,1);
    for(int i =1;i<n;i++){
        if(temp[i].first > temp[i-1].first){
            rank++;
            ans[temp[i].second] = rank;
        }else{
            ans[temp[i].second]=rank;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of the array :  ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arr= arrayRankTransform(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}