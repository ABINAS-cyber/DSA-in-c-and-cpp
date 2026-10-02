#include<bits/stdc++.h>
using namespace std;

// naive approach
int func(vector<int> wt,int cap){
    int n = wt.size();
    int day = 1 , load = 0;
    for(int i = 0;i<n;i++){
        if(wt[i] + load > cap){
            day += 1;
            load=wt[i];
        }else{
            load +=wt[i];
        }
    }
    return day;
}

int shipWithinDays(vector<int> wt, int D) {
    int n = wt.size();
    int low = *max_element(wt.begin(), wt.end());   // minimum capacity
    int high = accumulate(wt.begin(), wt.end(), 0); // maximum capacity

    for (int cap = low; cap <= high; cap++) {
        if (func(wt, cap) <= D) {
            return cap; // first capacity that works
        }
    }
    return -1; // not possible
}
// tc : O(sum - max) + 1 x O(N) ~ O(N²)
// sc : O(1)



// optimal approach
int f(vector<int> wt,int cap){
    int n = wt.size();
    int day = 1 , load = 0;
    for(int i = 0;i<n;i++){
        if(wt[i] + load > cap){
            day += 1;
            load=wt[i];
        }else{
            load +=wt[i];
        }
    }
    return day;
}

int shipwithinday(vector<int>wt,int days){
    int low = *max_element(wt.begin(),wt.end());
    int high = accumulate(wt.begin(),wt.end(),0);
    while(low <= high){
        int mid = (low + high) / 2;
        int noofday = f(wt,mid);
        if(noofday <= days){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

// tc : O(log2(sum - max  + 1) x O(N)
// sc : O(1)

int main() {
    int n, D;
    cout << "Enter number of packages: ";
    cin >> n;
    vector<int> wt(n);
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) cin >> wt[i];
    cout << "Enter number of days: ";
    cin >> D;

    // int result = shipWithinDays(wt, D);
    int result = shipwithinday(wt,D);
    if (result == -1) {
        cout << "It is not possible to ship within " << D << " days." << endl;
    } else {
        cout << "Minimum ship capacity required: " << result << endl;
    }
    return 0;
}