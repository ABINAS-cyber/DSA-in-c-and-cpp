#include<bits/stdc++.h>
using namespace std;

int getsum(int a ,int b){
    while (b!=0)
    {
        int sum = a^b;
        int carry = (a&b) << 1;
        a= sum;
        b=carry;
    }
    return a;
}

int getSum(int a, int b) {
        while (b != 0) {
            int sum = a ^ b; // sum without carry
            int carry = (a & b) << 1; // carry shifted left
            a = sum;
            b = carry;
        }
        return a;
    }

int main(){
    int x,y;
    cout<<"Enter the first number : ";
    cin>>x;
    cout<<"Enter the second number : ";
    cin>>y;
    cout<<"the sum without + and - operator is : "<<getsum(x,y);
    return 0;
}

