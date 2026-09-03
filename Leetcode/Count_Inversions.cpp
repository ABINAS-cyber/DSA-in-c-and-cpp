#include<bits/stdc++.h>
using namespace std;


// brute solutions
int numberinversion(vector<int>arr){
    int n = arr.size();
    int cnt =0 ;
    for(int i =0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                cnt++;
            }
        }
    }
    return cnt;
}
// tc: O(N^2)
// sc : O(1)



// optimal solutions
// int cnt = 0  do not declare global variables in the interview it is highly discouraged
int merge(vector<int>&arr,int low,int mid,int high){
    vector<int> temp;
    int left = low, right = mid + 1;

    // storing element in the temperorary array in a sorted manner
    int cnt = 0;
    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        // right is smaller
        else{
            temp.push_back(arr[right]);
            cnt+=(mid - left + 1);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
    return cnt;
}

int mergesort(vector<int>&arr,int low,int high){
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = low + (high - low) / 2;
    cnt += mergesort(arr,low,mid);
    cnt += mergesort(arr,mid+1,high);
    cnt += merge(arr,low,mid,high);
    return cnt;
}

int numberofInversion(vector<int>& a,int n){
    return mergesort(a,0,n-1);
}
// tc:O(NlogN)
// sc:O(N)


int main(){
    cout << "Enter the size of array: ";
    int size;
    cin >> size;
    vector<int> arr(size);
    for(int i = 0; i < size; i++){
        cout << "Enter element for index " << i << ": ";
        cin >> arr[i];
    }
    int n = arr.size();
    cout<<"using brute solution : "<<endl;
    cout<<"The pair of left greater than right is : "<<numberinversion(arr)<<endl;
    cout<<"Using mergesort optimal solution "<<endl;
    cout<<"The pair of left greater than right is : "<<numberofInversion(arr,n);

    return 0;
}