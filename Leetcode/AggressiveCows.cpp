#include<bits/stdc++.h>
using namespace std;

// brute force approach
bool canweplace(vector<int>& arr,int dist,int cows){
    int cntcow = 1 , last = arr[0];
    for(int i =1 ;i<arr.size();i++){
        if(arr[i] - last >= dist){
            cntcow++;
            last = arr[i];
        }
    }
    if(cntcow >= cows) return true;
    else return false;
}

int  aggressive_cow(vector<int>& arr,int cows){
    sort(arr.begin(),arr.end());
    for(int i = 1;i<arr.back()-arr.front();i++){
        if(canweplace(arr,i,cows)){
            continue;
        }
        else{
            return (i - 1);
        }
    }
}

// tc : O(max - min) x O(N)
// sc : O(1)



// optimal approach
int Aggressivecow(vector<int>& arr,int cows){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int low = 1, high = arr[n-1] - arr[0];
    while(low <= high){
        int mid = (low + high) / 2;
        if(canweplace(arr,mid,cows)){
            low = mid + 1;
        }else{
            high = mid - 1; 
        }
    }
    return high;
}
// tc : O(Nlogn) + O(log2(max - min)) x O(N)
// sc : O(1)


int main() {
    int n, cows;
    cout << "Enter number of stalls: ";
    cin >> n;
    cout << "Enter number of cows: ";
    cin >> cows;

    vector<int> stalls(n);
    cout << "Enter stall positions: ";
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    int result = Aggressivecow(stalls, cows);
    cout << "Maximum minimum distance = " << result << endl;

    return 0;
}