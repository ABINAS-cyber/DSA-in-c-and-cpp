#include<bits/stdc++.h>
using namespace std;


int first(vector<int>&arr,int n,int x){
    int low =0, high = n - 1 ;
    int first = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == x){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}

int last(vector<int>&arr,int n,int x){
    int low =0, high = n - 1 ;
    int last = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == x){
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < x){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return last;
}


pair<int,int> Firstandlastposition(vector<int>&arr,int n,int k){
    int firsts = first(arr,n,k);
    if(firsts == -1) return {-1,-1};
    int lasts = last(arr,n,k);
    return {firsts,lasts};
}


int count(vector<int>&arr,int n,int x){
    pair<int,int> ans = Firstandlastposition(arr,n,x);
    if(ans.first == -1) return 0;
    return ans.second - ans.first + 1;
}



int main(){
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements (sorted array): ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int x;
    cout << "Enter target element: ";
    cin >> x;

    cout << "Count of " << x << " = " << count(arr,n,x) << endl;

    return 0;
}