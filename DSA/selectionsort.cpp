#include<bits/stdc++.h>
using namespace std ;


void selection_sort(int arr[], int n){
    for(int i=0 ; i<=n-2 ;i++){ // n-2 because last element will be automatically sorted and no . of comparisons will be needed for it
        int min_index = i; 
        for(int j=i ; j<=n-1 ;j++){  // n-1 because we have to compare with last element also and j starts from i because before i all the elements are already sorted
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index]);
    } 
}


int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++) cin>>arr[i];
    selection_sort(arr,n);
    for(int i=0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
    return 0;   
}