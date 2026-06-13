#include<bits/stdc++.h>
using namespace std ;


// brute force approach 
vector<int> sortedarray(vector<int> arr1,vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    set<int> st;
    for(int i=0;i<n1;i++){
        st.insert(arr1[i]);
    }
    for(int i =0 ;i<n2;i++){
        st.insert(arr2[i]);
    }
    vector<int> temp;
    for(auto it:st){
        temp.push_back(it);
    }
    return temp;
}


// optimal approach
vector<int> sortedArrays(vector<int> a , vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int i=0;
    int j=0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }


    // remaining element will be iterated if one array got exhausted   
    while(j<n2){
        if(unionArr.size() == 0 || unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
        }
        j++;
    }

    
    while(i<n1){
        if(unionArr.size() == 0 || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }
    return unionArr;
}


int main(){
    cout<<"Enter the size of the 1st array : "<<endl;
    int n1;
    cin>> n1;
    vector<int> arr1(n1);
    for(int i = 0;i<n1;i++){
        cin>>arr1[i];
    }
    cout<<"Enter the size of the 2nd array :"<<endl;
    int n2;
    cin>>n2;
    vector<int> arr2(n2);
    for(int i = 0 ; i< n2;i++){
        cin>>arr2[i];
    }
    vector<int> uniona;
    uniona=sortedArrays(arr1,arr2);
    for(auto i : uniona){
        cout<<i;
    }
    cout<<endl;
    return 0;
}