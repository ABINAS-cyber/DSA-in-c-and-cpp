#include<bits/stdc++.h>
using namespace std;

int kthGrammar(int n , int k){
    if(n==1 || k==1) return 0;
    int mid = (1 << (n-1)) / 2;
    if(k <= mid){
        return kthGrammar(n-1,k);
    }
    else{
        return 1-kthGrammar(n-1,k-mid);
    }
}

int main(){
    int n;
    cout<<"Enter the no.of row : ";
    cin>>n;
    int k;
    cout<<"Enter the value of col element : ";
    cin>>k;
    cout<<kthGrammar(n,k);
    return 0;
}