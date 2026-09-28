#include<bits/stdc++.h>
using namespace std;

// naive approach
int findmax(vector<int>& v){
    int maxi = INT_MIN;
    int n =v.size();
    for(int i =0;i<n;i++){
        maxi=max(maxi,v[i]);
    }
    return maxi;
}

int calculatetotalhours(vector<int>& v,int hourly){
    int totalhours=0;
    int n = v.size();
    for(int i = 0;i<n;i++){
        totalhours += ceil((double)v[i] / (double)hourly);
    }
    return totalhours;
}

int minimumratetoeatbananas(vector<int> v,int h){
    for(int i = 1;i< findmax(v)/* or *max_element(v.begin(),v.end())*/;i++){
        int reqtime = calculatetotalhours(v,i);
        if(reqtime <= h){
            return i;
        }
    }
}
// tc : O(max(el) x N)
// sc : O(1)


//optimal approach
int calculateTotalHours(vector<int>& v,int hourly){
    int totalH =0 ;
    int n = v.size();
    for(int i = 0;i<n;i++){
        totalH += ceil((double)v[i] / (double)hourly);
    }
    return totalH;
}


int minimumRateToEatBanana(vector<int> v,int h){
    int low = 1 , high = findmax(v);
    while (low <= high)
    {
        int mid = (low+high)/2;
        int totalH = calculateTotalHours(v,mid);
        if(totalH <= h){
            high = mid - 1;
        }
        else{
            low= mid  + 1;
        }
    }
    return low;
}
// tc: O(log2(max(el) x N))
// sc : O(1)



int main() {
    int n, h;
    cout << "Enter number of piles: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter pile sizes: ";
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << "Enter total hours: ";
    cin >> h;

    cout << "Minimum eating rate: " << minimumRateToEatBanana(v, h) << endl;
    return 0;
}