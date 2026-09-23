#include<bits/stdc++.h>
using namespace std;

// brute approach
int peak_element(vector<int>& arr){
    int n = arr.size();
    for(int i =0 ;i<n;i++){
        if((i==0 || arr[i-1] < arr[i]) && (i==n-1 || arr[i] > arr[i+1]))
        {
        return i;
        }
    }
    return -1;
}
// tc : O(N)
// sc : O(1)


// optimal approach
int find_peak_element(vector<int>& arr){
    int n = arr.size();
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n - 1] > arr[n - 2]) return n - 1;
    int low = 1 , high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] > arr[mid - 1] &&  arr[mid] > arr[mid + 1]) {
            return mid;
        }
        else if(arr[mid] > arr [mid - 1]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
} 

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int bruteIndex = peak_element(arr);
    int optimalIndex = find_peak_element(arr);

    cout << "Peak element index (brute): " << bruteIndex 
         << " value: " << arr[bruteIndex] << endl;
    cout << "Peak element index (optimal): " << optimalIndex 
         << " value: " << arr[optimalIndex] << endl;

    return 0;
}