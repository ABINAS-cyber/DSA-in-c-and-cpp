#include<bits/stdc++.h>
using namespace std;

// with upper bound and lower bound 
int lowerbound(vector<int>&arr,int n,int target){
    int low = 0 , high = n-1;
    int ans=n;
    while(low <= high){
        int mid = ( low + high ) / 2;
        if(arr[mid] >= target){
            ans = mid;
            high  = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}


int upperbound(vector<int>&arr,int n,int target){
    int low = 0 , high = n-1;
    int ans=n;
    while(low <= high){
        int mid = ( low + high ) / 2;
        if(arr[mid] > target){
            ans = mid;
            high  = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;    
}


pair<int,int> firstandlastposition(vector<int>&arr,int n,int k){
    int lb = lowerbound(arr,n,k);
    if(lb  == n || arr[lb] != k) return {-1,-1};
    return  {lb,upperbound(arr,n,k) - 1};
}


// with noraml binarysearch
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

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the target value: ";
    cin >> k;

    // pair<int,int> ans = firstandlastposition(arr, n, k);
    pair<int,int> ans = Firstandlastposition(arr, n, k);
    if (ans.first == -1) {
        cout << "Target not found in array." << endl;
    } else {
        cout << "First position: " << ans.first << endl;
        cout << "Last position: " << ans.second << endl;
    }  

    return 0;
}