#include<bits/stdc++.h>
using namespace std;


// brute force approach
void merge(long long arr1[],long long arr2[],int n ,int m){
    long long arr3[n + m];
    int left = 0;
    int right = 0;
    int index =0;
    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            arr3[index] = arr1[left];
            left++,index++;
        }else{
            arr3[index] = arr2[right];
            right++,index++;
        }
    }
    while(left < n){
        arr3[index++] = arr1[left++];
    }
    while(right < m){
        arr3[index++] = arr2[right++];
    }
    for(int i =0;i<n+m;i++){
        if(i < n) arr1[i] = arr3[i];
        else arr2[i - n] = arr3[i];
    }
}
// tc : O(n + m) + O(n + m)
// sc : O(n + m)


// 1> optimal solution
void Merge(long long arr1[],long long arr2[],int n ,int m){
    int left = n-1;
    int right = 0;
    while(left >=0 && right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left],arr2[right]);
            left--,right++;
        }
        else{
            break;
        }
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}
// tc : O(min(n,m)) + O(nlogn) + O(mlogm)
// sc : O(1)


// 2> optimal solution
void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
        if(arr1[ind1] > arr2[ind2]) {
            swap(arr1[ind1], arr2[ind2]);
        }
    }

void MergE(long long arr1[], long long arr2[], int n, int m) {
        int len = (n + m);
        int gap = (len / 2) + (len % 2);
        while(gap > 0) {
            int left = 0;
            int right = left + gap;
            while(right < len) {
                // arr1 and arr2
                if(left < n && right >= n) {
                    swapIfGreater(arr1, arr2, left, right - n);
                }
                // arr2 and arr2
                else if(left >= n) {
                    swapIfGreater(arr2, arr2, left - n, right - n);
                }
                // arr1 and arr1
                else {
                    swapIfGreater(arr1, arr1, left, right);
                }
                left++, right++;
            }
            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }




int main(){
    int n ;
    cout<<"Enter the size of the 1st array : ";
    cin>>n;
    int m ;
    cout<<"Enter the second array size : ";
    cin>>m;
    long long arr1[n];
    cout<<"Enter the elements for array 1 : ";
    for(int i =0;i<n;i++){
        cin>>arr1[i];
    }

    long long arr2[m];
    cout << "Enter the elements for array 2 : ";
    for(int i =0;i<m;i++){
        cin>>arr2[i];
    }

    // brute approach :
    // merge(arr1,arr2,n,m);

    // optimal one solution : 
    // Merge(arr1,arr2,n,m);


    // optimal second solution :
    MergE(arr1,arr2,n,m); 

    cout<<"The array1  is : ";
    for(int i =0;i<n;i++){
        cout<<arr1[i] << " ";
    }

    cout<<"The array2  is : ";
    for(int i =0;i<m;i++){
        cout<<arr2[i] << " " ;
    }
    return 0;
}