#include<bits/stdc++.h>
using namespace std;


// Bruteforce approach 
void rearrange_array(vector<int> &arr){
    int n = arr.size();
    vector<int> pos,neg;
    for(int i =0 ;i<n;i++){
        if(arr[i] >=0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    for(int i =0 ; i<n/2;i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
}
// tc : O(N) + O(N/2) = O(2N)
// sc : O(N)



// ex : 3,1,-2,-5,2,-4
// Bruteforce approach optimize 
vector<int> rearrangeArray(vector<int> & arr){
    int n = arr.size();
    vector<int> ans(n,0);
    int postIndex = 0 , negIndex = 1;
    for(int i =0 ;i<n;i++){
        if(arr[i] < 0){
            ans[negIndex] = arr[i];
            negIndex+=2;
        }
        else{
            ans[postIndex] = arr[i];
            postIndex+=2;
        }
    } 
    return ans;
}


// 2nd variety of the  problem  if pos!=neg
vector<int> alternateNumbers(vector<int> &arr){
    vector<int> pos,neg;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }

    if(pos.size() >  neg.size()){
        for(int i =0;i<neg.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i= neg.size();i<pos.size();i++){
            arr[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i =0;i<pos.size();i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i= pos.size();i<neg.size();i++){
            arr[index] = neg[i];
            index++;
        }
    }
    return arr;
}

// tc : O(N) + O(min(pos,neg)) + O(leftover)
// sc : O(N)

 


int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter the element : "<<"\n";
    for(int i=0;i<n;i++) cin >> arr[i];
    // rearrange_array(arr);
    arr = alternateNumbers(arr);
    for(int i=0;i<n;i++) cout << arr[i]<<" ";
    return 0;
}