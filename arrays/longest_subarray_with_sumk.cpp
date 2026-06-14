// subarray : contigous part of the array

// ex: {1,2,3,1,1,1,1,4,2,3}

// so subarray can be {1,2} from index 0 and 1 with length 2
// but it can 't be subarray {1,2} from index any of 1 is present in array
//  of index,and at index 8 which is 2 which is not continous so no subarray
// another no subarray is {1,3}  it is a subsequence


#include<bits/stdc++.h>
using namespace std;


// brute force approach
int longest_subarray(vector<int> arr,int n,int k){
    int len=0;
    for(int i=0;i<n;i++){
        for(int j = i;j<n;j++){ 
            int sum=0;
            for(int k=i;k<=j;k++){ 
                sum+=arr[k];
            }
            if(sum==k) len=max(len,j-i+1);
        }
    }
    return len;
}


//brute force  solutions can be optimized   
int longestsubarray(vector<int> arr,int n,int kth){
    int len=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j = i;j<n;j++){ 
           sum+=arr[j];
            if(sum==kth) return len=max(len,j-i+1);
        }
    }
    return len;
}


// better approach
int longestsubarraywithsumk(vector<int> a,long long k){
    map<long long,int> preSumMap;
    long long sum = 0;
    int maxlen = 0;
    for(int i =0;i<a.size();i++){
        sum+=a[i];
        if(sum == k){
            maxlen=max(maxlen,i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxlen = max(maxlen,len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){ // was the sum previsoly
            // not there if it was not there previously then put it
            preSumMap[sum] = i;   
        }
    }
    return maxlen;
}


// if the arrays has negative ,zero and poistive , then the optimal approach
int getlongestsubarray(vector<int> &a , int k){
    map<long long,int> preSumMap;
    long long sum = 0;
    int maxlen = 0;
    for(int i =0;i<a.size();i++){
        sum+=a[i];
        if(sum == k){
            maxlen=max(maxlen,i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxlen = max(maxlen,len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){ // was the sum previsoly
            // not there if it was not there previously then put it
            preSumMap[sum] = i;   
        }
    }
    return maxlen;
}


// the tc is big-oh(n*logn) if we are using ordered-map in cpp or
// else it will be big-oh(n*1) if we are using un-oredered map
// but again if it goes to the worst case like constraints are in such
// a way that it ends up having lot of collisions then this 1 that big-oh(1) 
// search -time in the map ends up  being big-oh(n)
// hence the worst case can be big-oh(n^2) if we use un-ordered map
// sc wil be big-oh(n)


// optimal approach 





int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    vector<int> arr(n);
    cout<<"enter the elements :";
    for(int i = 0 ;i<n;i++){
        cin>>arr[i];
    }
    int kth;
    cout<<"Enter the sum of the sub arrays";
    cin>>kth;
    cout << "the longest subarray is :"<<longestsubarraywithsumk(arr,kth);
    return 0;
}