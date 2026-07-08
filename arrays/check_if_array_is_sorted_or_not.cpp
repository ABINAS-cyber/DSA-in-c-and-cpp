#include<bits/stdc++.h>
using namespace std;

bool checkSorted(int arr[], int n){
    for(int i=1;i<n;i++){
        if(arr[i] >= arr[i-1]){
            continue;
        }
        else{
            return false;
        }
        return true;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(checkSorted(arr,n)){
        cout<<"The array is sorted in non-decreasing order."<<endl;
    }
    else{
        cout<<"The array is not sorted in non-decreasing order."<<endl;
    }
    return 0;
}