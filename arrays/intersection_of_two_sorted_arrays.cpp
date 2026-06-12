#include<bits/stdc++.h>
using namespace std;

// {1,2,2,3,4}
// {1,2,2,4,6} 
// ans -> {1,2,2,4}
// intersection:present in the both the arrays or common element in both
// with same no.of frequency


// brute force approach 
vector<int> intersection_sorted_array(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    int visit[n2] = {0};

    vector<int> ans;
    for(int i = 0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a[i] == b[j] && visit[j] == 0){
                ans.push_back(a[i]);
                visit[j]=1;
                break;
            }
            if(b[j] > a[i]) break;
        }
    }
    return ans;
}



// optimal approach
vector<int> findArrayIntersection(vector<int> a,vector<int> b){
    int n1=a.size();
    int n2=b.size();
    int i = 0;
    int j =0 ;
    vector<int> ans;
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            i++;
        }
        else if(b[j] < a[i]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}


int  main(){
    int n1;
    cout<<"Enter the size of 1st array :"<<endl;
    cin>>n1;
    vector<int> arr1(n1);
    for(int i =0 ;i<n1;i++){
        cin>>arr1[i];
    }

    int n2;
    cout<<"enter the size of the 2nd array :"<<endl;
    cin>>n2;
    vector<int> arr2(n2);
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }

    vector<int> intersection;
    
    // intersection=intersection_sorted_array(arr1,arr2);

    intersection=findArrayIntersection(arr1,arr2);
    for(auto x : intersection ){
        cout<<x<<" ";
    }
    return 0;
}
