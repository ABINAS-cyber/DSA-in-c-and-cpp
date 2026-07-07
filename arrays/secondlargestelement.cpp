#include<bits/stdc++.h>
using namespace std;

// Better solution with time complexity O(n) and space complexity O(1)
void slargest(int arr[],int n){
    int largest = arr[0];
    int secondlargest = -1;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    for(int i=1 ; i<n ; i++){
        if(arr[i]>secondlargest && arr[i]<largest){
            secondlargest = arr[i];
        }
    }
    cout<<"The second largest element in the array is: "<<secondlargest<<endl;
}



// optimal solution with time complexity O(nlogn) and space complexity O(1)`
// Note: if in the element -ve number is present then we have to initialize secondlargest with INT_MIN

int secondLargest(int arr[],int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i]<largest && arr[i]>slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int secondSmallest(int arr[], int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i]<smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] != smallest && arr[i]<ssmallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

int getsecondorderelement(int arr[], int n){
    int slargest = secondLargest(arr,n);
    int ssmallest = secondSmallest(arr,n);
    return (slargest,ssmallest);
}



int main(){
     int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }
    slargest(arr, n);
    cout<<"The second largest and smallest elements are: "<<getsecondorderelement(arr, n)<<endl;
    return 0;
}