#include<bits/stdc++.h>
using namespace std;

void rightrotatebyreverse(int arr[],int n,int d){
    d=d%n; // In Case the number of places to rotate is greater than the size of the array
    reverse(arr,arr+n-d);
    reverse(arr+n-d,arr+n);
    reverse(arr,arr+n);
}

void rightrotatebyk(int arr[],int n,int d){
    d=d%n; // In Case the number of places to rotate is greater than the size of the array
    int temp[n];
    for(int i=0;i<n;i++){
        temp[(i+d)%n]=arr[i];
    }
    for(int i = 0; i < n; i++){
        arr[i] =  temp[i];
    }
}

void rightrotatebyk2(int arr[],int n,int d){
    d=d%n; // In Case the number of places to rotate is greater than the size of the array
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[n-d+i];
    }
    for(int i = n-1 ; i >= d ; i--){
        arr[i]=arr[i-d];
    }
    for(int i = 0; i < d; i++){
        arr[i] =  temp[i];
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
    rightrotatebyk(arr,n,d);
    cout<<"The array after right rotation by "<<d<<" places is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    // cout<<endl;
    // cout<<"Using the optimal approach: "<<endl;
    // rightrotatebyreverse(arr,n,d);
}