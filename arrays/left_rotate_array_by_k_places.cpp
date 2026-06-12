#include<bits/stdc++.h>
using namespace std;

// brute force approach: O(n+d) time complexity
// void leftrotatebyk(int arr[],int n,int d){
//     d=d%n; // In case the number of places to rotate is greater than the size of the array
//     int temp[d];
//     for(int i=0;i<d;i++){
//         temp[i]=arr[i];
//     }
//     for(int i = d ; i < n ; i++){
//         arr[i - d]=arr[i];
//     }
//     for(int i = n-d; i < n; i++){
//         arr[i] =  temp[i - (n-d)];
//     }
// }

void leftrotatebyk2(int arr[],int n,int d){
    d=d%n; // In case the number of places to rotate is greater than the size of the array
    int temp[n];
    for(int i=0;i<n;i++){
        temp[i]=arr[(i+d)%n];
    }
    for(int i = 0; i < n; i++){
        arr[i] =  temp[i];
    }
}


// optimal approach: O(n) time complexity and O(1) space complexity
void leftrotatebyreverse(int arr[],int n,int d){
    d=d%n; // In case the number of places to rotate is greater than the size of the array
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
}


// if you dont have the reverse function available, you can implement it as follows:
void reversef(int arr[],int start,int end){
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}


int main(){
    int n,d;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number of places to rotate: ";
    cin>>d;
    // leftrotatebyk(arr,n,d);
    // cout<<"The array after left rotation by "<<d<<" places is: ";
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    cout<<endl;
    cout<<"Using the optimal approach: "<<endl;
    leftrotatebyreverse(arr,n,d);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
} 