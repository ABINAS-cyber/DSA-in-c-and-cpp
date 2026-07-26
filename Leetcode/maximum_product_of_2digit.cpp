#include<bits/stdc++.h>
using namespace std;

int maxproduct(int n){
    int first = 0, second = 0;
    while(n>0){
        int x = n % 10;
        if(x > first){
            second = first;
            first = x;
        }
        else if (x > second){
            second = x;
        }
        n/=10;
    }
    return first * second;
}

int main(){
    int n ;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<maxproduct(n);
    return 0;
}