#include<bits/stdc++.h>
using namespace std;


// brute force approach tc is big-oh(n^2)
vector<int> two_sum(vector<int> &a ,int t){
    int n=a.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue ;
            if(a[i] + a[j] == t) return {i,j};
        } 
    }
}


// brute force optimisation 
vector<int> twosum(vector<int> a,int t){
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i] + a[j] == t) return {i,j};
        } 
    }
}


//better approach  
// tc  : big-oh(n) if map works on big-oh(1) 
// if map work on log n then tc is big-oh(n log n)
// big-oh(n) when we take an un -ordered map in the best and average case
// in the worst case   of un-ordered map it can go upto big-oh(n^2) complexity
// sc is big-oh(n)
string twoSum(vector<int> arr ,int t){
    int n= arr.size();
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        int a = arr[i];
        int more = t - a;
        if(mpp.find(more) != mpp.end()){
            return "YES"; //return {mpp[more],i};
        }
        mpp[a] = i;
    }
    return "NO"; // return {-1,-1};
}


// slightly better solutions
// without using map datastucture
// tc is big-oh(n) + big-oh(nlogn) <-for sorting 
// sc is big-oh(1)
// i am not using anything extra but i am sorting array
// if you wanna consider that sorted array complexity well and good that 
// is big-oh(n) and if you don't want it is big-oh(1)
string TwoSum(vector<int> arr,int t){
    int left =0 ,right = arr.size()-1;
    sort(arr.begin(),arr.end());
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == t){
            return "YES";
        }
        else if (sum < t) left++;
        else right--;
    }
    return "NO";
}


int main(){
    int size;
    cout<<"Enter the size of an array ";
    cin>>size;
    vector<int> arr(size);
    cout<<"enter the elements : ";
    for(int i =0 ;i<size;i++){
        cin>>arr[i];
    }
    int target;
     cout << "Enter the target value: ";
    cin >> target;
    
    vector<int> ans = two_sum(arr, target);
    if(!ans.empty()){
        cout << "The two sum indices are: " << ans[0] << " and " << ans[1] << endl;
    } else {
        cout << "No valid pair found." << endl;
    }
    return 0;
}