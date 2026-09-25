#include<bits/stdc++.h>
using namespace std;

// brute force
int find_sqrt_of_a_number(int n){
     int ans ;
    for(int i = 1;i <= n;i++){
        if(i * i <= n){
            ans = i;
        }else{
            break;
        }
    }
    return ans;
}
// tc : O(N)
// sc : O(1)


// optimal solution
int floorsqrt(int n){
    int low = 1 , high = n ;
    while(low <= high){
        int mid = (low + high) / 2;
        if(mid * mid <= n){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}


int main(){
    int n ;
    cin>>n;
    cout<<find_sqrt_of_a_number(n)<<endl;
    cout<<floorsqrt(n);
    return 0;
}