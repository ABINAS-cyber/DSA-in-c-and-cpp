#include<bits/stdc++.h>
using namespace std;

// Better approach 
void sort_an_array_of_0s_1s_2s(vector<int> arr){
    int cnt0 =0 , cnt1=0 , cnt2=0 ;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }
    for(int i=0;i<cnt0;i++) arr[i] =0;
    for(int i=cnt0;i<cnt0+cnt1;i++) arr[i] = 1;
    for(int i=cnt0+cnt1;i<n;i++) arr[i] = 2;
}


// most optimal solution 
// by using Dutch National Flag (DNF) proposed by Edsger Dijkstra
void sortarray(vector<int> &arr){
    int n = arr.size();
    int low = 0 , mid = 0 , high = n-1 ;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }

}
// tc : big-oh(n)
// sc : big-oh(1)

// ex : {0,1,1,0,1,2,1,2,0,0,0}
// array size = 11


int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element :";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    sortarray(arr);
    cout<<"After using DNF we got the sorted array as :";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}