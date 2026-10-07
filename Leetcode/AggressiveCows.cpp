#include<bits/stdc++.h>
using namespace std;


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
    for(int i = 1;i<arr.size();i++){
        if(canweplace(arr,i,cows)){
            continue;
        }
        else{
            return (i - 1);
        }
    }
}


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

    int result = aggressive_cow(stalls, cows);
    cout << "Maximum minimum distance = " << result << endl;

    return 0;
}