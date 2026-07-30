#include<bits/stdc++.h>
using namespace std;

// ex : xycdefghij

// Greedy Approach
int minimumpushes(string word){
    int n = word.length();
    int ans =0;
    for(int i = 0;i<n;i++){
        ans +=i/8+1;
    }
    return ans;
}

// mathmatical approach or optimal approach 
int minimum_pushes(string word){
    int n = word.length();
    
}

int main(){
    string s;
    getline(cin,s);
    cout<<"the minimum pushes required are : "<<minimumpushes(s);
    return 0;
}