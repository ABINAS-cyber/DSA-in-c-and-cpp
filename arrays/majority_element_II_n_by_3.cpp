#include<bits/stdc++.h>
using namespace std;



// most naive brute approach
vector<int> majority_element_2(vector<int> arr){
    vector<int> ls;
    int n = arr.size();
    for(int i = 0; i<n ;i++){
        if(ls.size()==0 ||(ls.size() == 1 && ls[0] != arr[i])){
            int cnt = 0;
            for(int j =0;j<n;j++){
                if(arr[i]==arr[j]){
                    cnt++;
                }
            } 
            if(cnt > n/3){
                ls.push_back(arr[i]);
            }
        }
        if(ls.size() == 2);
    }
    return ls;
}
// tc : O(N^2)
// sc : O(1) constant space 





// better approach
vector<int> Majority_element_2(vector<int> arr){
    vector<int> ls;
    int n = arr.size(); map<int,int> mpp; int mm = (n/3)+1;
    for(int i = 0 ; i<n;i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]] == mm){
            ls.push_back(arr[i]);
        }
        if(ls.size() == 2);
    }
    // O(2 log 2) as good as constant
    sort(ls.begin(),ls.end());
    return ls;
}
// tc : O(N) * O(log N) -> O(NlogN)
// sc : O(N) because if enter the array as [1,2,3,4]
// then you end up putting all the element in to the list 




// optimal approach 
vector<int> Majority_Element_2(vector<int> arr){
    int cnt1 = 0 , cnt2 = 0 ;
    int el1 = INT_MIN , el2 = INT_MIN ;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(cnt1 == 0 && arr[i] != el2){
            cnt1 = 1;
            el1 = arr[i];
        }
        else if(cnt2 == 0 && arr[i] != el1){
            cnt2 = 0;
            el2 = arr[i];
        }
        else if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ls;
    cnt1 = 0 , cnt2 = 0;
    for(int i=0;i<n;i++){
        if(el1 == arr[i]) cnt1++;
        else if(el2 == arr[i]) cnt2++;
    }
    int mini = (int)(n/3) + 1;
    if(cnt1 >= mini) ls.push_back(el1);
    if(cnt2 >= mini) ls.push_back(el2);
    sort(ls.begin(),ls.end());
    return ls;
}






int main(){
    int n;
    cout<< "Enter the size of array : ";
    cin>> n;
    vector<int> arr(n);
    cout<<"Enter the elements : ";
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    // arr = majority_element_2(arr);
    arr = Majority_element_2(arr);
    for(auto it : arr){
        cout<<it<<" ";
    }
    return 0;
}