#include<bits/stdc++.h>
using namespace std;


void leftrotate(int arr[],int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
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
    leftrotate(arr,n);
    cout<<"The array after one left rotation is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}