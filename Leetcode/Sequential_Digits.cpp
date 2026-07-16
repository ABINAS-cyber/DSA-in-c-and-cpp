#include<bits/stdc++.h>
using namespace std;

vector<int> gsl(){
        vector<int> sqdigit;
    for(int length =2 ;length<=9;length++){           
        for(int start  =1;start<=10-length;start++){
            int num=0;
            for(int i =0 ;i<length;i++){
                num=num*10+(start + i);
            }
            sqdigit.push_back(num);
        }
    }
    return sqdigit;
} 

vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;
    vector<int> sqdigit = gsl();
    for(int num : sqdigit){
        if(num>=low && num<=high){
            ans.push_back(num);
        }
    }
    return ans;
}
       
int main(){
    int low , high;
    cout<<"Enter the low: ";
    cin>>low;
    cout<<"Enter the high : ";
    cin>>high;
    vector<int> res = sequentialDigits(low,high);
    for(int num : res){
        cout<<num<<" ";
    }
    return 0;
}