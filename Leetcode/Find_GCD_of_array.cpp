#include<bits/stdc++.h>
using namespace std;

int FindGcd(vector<int> arr){
    int mx = *max_element(arr.begin(),arr.end());
    int mn = *min_element(arr.begin(),arr.end());
    return __gcd(mx,mn);
}

int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element: ";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The GCD of array is : "<<FindGcd(arr);
    return 0;
}