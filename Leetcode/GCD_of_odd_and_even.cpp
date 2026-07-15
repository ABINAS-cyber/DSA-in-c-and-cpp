#include<bits/stdc++.h>
using namespace std;

int gcd_of_even_and_odd(int n){
    int sumeven=0;
    for(int i=2;i<=2*n;i+=2){
        sumeven+=i;
    }
    int sumodd=0;
    for(int i=1;i<2*n;i+=2){
        sumodd+=i;
    }
    for(int i=min(sumeven,sumodd);i>0;i--){
        if(sumeven % i ==0 && sumodd%i==0){
            return i;
        }
    }
    return 1;
}

int Gcd_of_even_and_odd(int n){
    int sumeven=0;
    int sumodd=0;
    for(int i=1;i<=n;i++){
        sumeven += (2*i);
        sumodd +=(2*i-1);
    }
    for(int i=min(sumeven,sumodd);i>0;i--){
        if(sumeven % i ==0 && sumodd%i==0){
            return i;
        }
    }
    return 1;
}


int main(){
    int n;
    cout<<"Enter the 1st number : ";
    cin>>n;
    cout<<Gcd_of_even_and_odd(n);
    return 0;
}