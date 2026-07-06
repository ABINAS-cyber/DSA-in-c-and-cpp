#include<bits/stdc++.h>
using namespace std;

// Brute force solution with time complexity O(nlogn) and space complexity O(n) 

void removeDuplicates(int arr[], int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    int index = 0;
    for(auto it : s){
        arr[index] = it;
        index++;
    }
}


// optimal solution with time complexity O(n) and space complexity O(1)
int rd(int arr[], int n){
    int i = 0;
    for(int j=1;j<n;j++){
        if(arr[i] != arr[j]){
            arr[i+1]=arr[j];            
            i++;
        }
    }
    return (i+1);
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
    // removeDuplicates(arr,n);
    rd(arr,n);
    cout<<"The array after removing duplicates is: "<<endl;   
    for(int i=0;i<n-1;i++){
        cout<<arr[i]<<" ";
    }

    cout<<"\n The legnth of the new array is :"<<rd(arr,n);
    return 0;
}