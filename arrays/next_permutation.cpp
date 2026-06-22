#include<bits/stdc++.h>
using namespace std;


// void reversef(vector<int> arr,int start,int end){
//     while(start<=end){
//         int temp=arr[start];
//         arr[start]=arr[end];
//         arr[end]=temp;
//         start++;
//         end--;
//     }
// }


vector<int> nextGreaterPermutation(vector<int> &arr){
    int ind=-1;
    int n=arr.size();
    for(int i = n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            ind=i;
            break;
        }
    }
    if(ind==-1) {
        reverse(arr.begin(),arr.end());
        return arr;
    }
    for(int i=n-1;i>ind;i--){
        if(arr[i]>arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    // reversef(arr,ind+1,n-1);
    reverse(arr.begin()+ ind + 1,arr.end());
    return arr;
}
// tc : O(3N);
// sc : O(N) if interviewer considsidering array otherwise
// sc : O(1)


int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element : "<<"\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    arr = nextGreaterPermutation(arr);
    for(int i=0;i<n;i++) cout << arr[i]<<" ";
    return 0;
}