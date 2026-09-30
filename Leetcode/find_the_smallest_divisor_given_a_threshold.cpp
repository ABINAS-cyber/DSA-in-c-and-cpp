#include<bits/stdc++.h>
using namespace std;

// naive aapproach
int smallestdivisor(vector<int>& arr,int threshold){
    int n = arr.size();
    for(int d =1;d<*max_element(arr.begin(),arr.end());d++){
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += ceil((double)(arr[i])/(double)(d));
        }
        if(sum <= threshold) return d;
    }
    return -1;
}
// tc : O(max * n)
// O(1)


// optimal approach
int sumbyd(vector<int>& arr,int div){
    int sum = 0;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int>&arr ,int limit){
    int low =1,high=*max(arr.begin(),arr.end());
    while (low <= high){
        int mid = (low + high) / 2;
        if(sumbyd(arr,mid) <= limit){
            high = mid-1;
        }
        else{
            low= mid + 1;
        }
    }
    return low;
}
// tc : O(log2max) * N
// sc : O(1)

int main(){
    int n, limit;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Enter limit: ";
    cin >> limit;

    int ans = smallestdivisor(arr, limit);
    cout << "Smallest divisor is: " << ans << endl;

    return 0;
}