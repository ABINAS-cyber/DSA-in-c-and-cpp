#include<bits/stdc++.h>
using namespace std;

// You are given a palindromic string s.
// Return the lexicographically smallest palindromic permutation of s.



// ex:babab or daccad
string smallestPalindrome(string s) {
    int len = s.length();
    int partition = len / 2;
    sort(s.begin(),s.begin() + partition);

    for(int i =0 ;i < partition; i++){
        s[len -1 - i] = s[i];
    }
    return s;
}

int main(){
    string s;
    cout<<"Enter the string  : ";
    getline(cin,s);
    cout << "The palindromic rearrangement is : "<<smallestPalindrome(s);
    return 0;
}