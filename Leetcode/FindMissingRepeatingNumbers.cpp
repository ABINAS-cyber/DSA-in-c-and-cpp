#include<bits/stdc++.h>
using namespace std;


// extreme naive solution
vector<int> findmissingrepeatingnumbers(vector<int> a){
    int n=a.size();
    int repeating = -1;
    int missing =-1;
    for(int i =1;i<n;i++){
        int cnt =0;
        for(int j = 0;j<n-1;j++){
            if(a[j]==i){
                cnt++;
            }
        }
        if(cnt == 2) repeating =i;
        else if(cnt==0) missing = i;
        if(repeating != -1 && missing != -1){
            break;
        }
    }
}


// better solution:
vector<int> Findmissingrepeatingnumbers(vector<int> a){
    int n =a.size();
    int hash[n  + 1] = {0};
    for(int i = 0;i<n;i++){
        hash[a[i]]++;
    }

    int repeating  =-1;
    int missing= -1 ;
    for(int i =1;i<n;i++){
        if(hash[i] == 2) repeating =i;
        else if(hash[i] == 0) missing =i;
        if(repeating != -1 && missing != -1) {
            break;
        }
    }
    return {repeating,missing};
}
// tc:O(2N)
// sc:O(N)


// optimal solution 1 mathmatical :
vector<int> FindMissingrepeatingnumbers(vector<int>a){
    long long  n = a.size();
    // S - SN = x - y
    // S2 - S2N
    long long SN = (n*(n+1))/2;
    long long S2N = (n*(n+1)*(2*n+1))/6;
    long long S =0 , S2=0;
    for(int i =0;i<n;i++){
        S += a[i];
        S2 += (long)a[i] * (long)a[i];
    }

    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2 / val1;
    long long x = (val1+val2)/2;
    long long y = x - val1;
    return {(int)x,(int)y};
}
// tc : O(N)
// sc :O(1)


// optimal solution 2 XOR : 
vector<int> findmisMissingRepeatingNumber(vector<int> a){
    long long n = a.size();
    int xr = 0 ;
    for(int i = 0 ;i<n;i++){
        xr=xr ^ a[i];
        xr = xr ^ (i+1);
    } 


    int bitNo = 0;
    while(1){
        if((xr & (1<<bitNo)) != 0){
            break;
        }
        bitNo++;
    }

    int zero = 0;
    int one = 0;
    for(int i =0 ;i<n;i++){
        // part of one club
        if((a[i] & (1<<bitNo)) != 0){
            one = one ^ a[i];
        }
        // part of zeroth club 
        else{
            zero = zero ^ a[i];
        }
    }
    for(int i = 1; i <= n; i++){
    if((i & (1<<bitNo)) != 0){
        one = one ^ i;
    }
    else{
        zero = zero ^ i;
    }
}


    int  cnt = 0;
    for(int i = 0;i<n;i++){
        if(a[i] == zero) cnt++;
    }
    if(cnt == 2) return{zero,one};
    return {one,zero};
}


// instead of doing this do this for bit No
vector<int> findmisMissingRepeatingNumbers(vector<int> a){
    long long n = a.size();
    int xr = 0 ;
    for(int i = 0 ;i<n;i++){
        xr=xr ^ a[i];
        xr = xr ^ (i+1);
    } 
    int number = xr & ~(xr - 1);
    int zero = 0;
    int one = 0;
    for(int i =0 ;i<n;i++){
        // part of one club
        if((a[i] & (number)) != 0){
            one = one ^ a[i];
        }
        // part of zeroth club 
        else{
            zero = zero ^ a[i];
        }
    }
    for(int i = 1; i <= n; i++){
    if((i & (number)) != 0){
        one = one ^ i;
    }
    else{
        zero = zero ^ i;
    }
}


    int  cnt = 0;
    for(int i = 0;i<n;i++){
        if(a[i] == zero) cnt++;
    }
    if(cnt == 2) return{zero,one};
    return {one,zero};
}


// tc:~ O(N)
// sc: O(1)


int main() {
    int n;
    
    // 1. Take the size of the array as input
    cout << "Enter the size of the array: ";
    cin >> n;
    
    // 2. Create a vector of that size and take the elements as input
    vector<int> a(n);
    cout << "Enter " << n << " elements (from 1 to " << n << "): ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 3. Call your function (using your optimal math solution here)
    vector<int> ans = findmisMissingRepeatingNumbers(a);
    
    // 4. Print the results
    cout << "The repeating number is: " << ans[0] << "\n";
    cout << "The missing number is: " << ans[1] << "\n";

    return 0;
}