#include<bits/stdc++.h>
using namespace std;

// int cnt = 0; global variable not a good practice

void merge(vector<int>&arr,int low,int mid,int high){
    vector<int> temp;
    int left = low, right = mid + 1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
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
}

int countpairs(vector<int> &arr,int low ,int mid,int high){
    int right = mid + 1;
    int cnt = 0;
    for(int i = low ;i<=mid;i++){
        while (right<= high && (long long)arr[i] > 2LL*arr[right]) right++;
        cnt += (right-(mid + 1));
    }
    return cnt;
}

int  ms(vector<int>&arr,int low,int high){
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = low + (high - low) / 2;
    cnt += ms(arr,low,mid);
    cnt += ms(arr,mid+1,high);
    cnt+=countpairs(arr,low,mid,high);
    merge(arr,low,mid,high);
    return cnt;
}

int team(vector<int>& skils,int n){
    return ms(skils,0,n-1);
    // return cnt; used in global variables 
}
// tc : O(log n) * O(n1 + n2)  => O(2nlogn)
// sc : O(n)


int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Number of reverse pairs: " << team(arr, n) << endl;
    return 0;
}