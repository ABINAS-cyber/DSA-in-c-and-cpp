#include<bits/stdc++.h>
using namespace std ;


void bubble_sort(int arr[], int n){
    for(int i=n-1 ; i>=1 ;i--){ // no . of passes will be n-1 because after n-1 passes the array will be automatically sorted and no . of comparisons will be needed for it
        int didswap=0;
        for(int j=0 ; j<=i-1 ;j++){ // 
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap=1;
            }
        }
        if(didswap==0) break;
        cout<<"runs\n";
    }
}


int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++) cin>>arr[i];
    bubble_sort(arr,n);
    for(int i=0 ; i<n ;i++){ 
        cout<<arr[i]<<" ";
    }
    return 0;
}