#include<bits/stdc++.h>
using namespace std;


// brute force approach 
void markrow(int i,vector<vector<int>> &arr){
    int m = arr[0].size();
    for(int j = 0 ;j<m;j++){
        if(arr[i][j] != 0){
            arr[i][j] = -1;
        }
    }
}

void markcol(int j,vector<vector<int>> &arr){
    int n  = arr.size();
    for(int i = 0 ;i<n;i++){
        if(arr[i][j] != 0){
            arr[i][j] = -1;
        }
    }
}

vector<vector<int>> set_matrix_zeros(vector<vector<int>> &arr){
    int m = arr[0].size();
    int n = arr.size(); // row 
    for(int i=0;i<n;i++){
        for(int j = 0 ;j<m;j++){
            if(arr[i][j]==0){
                markrow(i,arr);
                markcol(j,arr);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
    return arr;
}

// tc : O(n x m) x ( n + m) + (n x m) nearly = O(n^3)
// sc : O()



// better approach 
vector<vector<int>> zeromatrix(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
    int row[n]={0};
    int col[m]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    // O(n x m)

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i] || col[j]){
                arr[i][j] = 0;
            }
        }
    }
    // O(n x m)
    return arr;
}
// tc : O(2 x n x m)
// sc : O(n) + O(m)


// optimal approach
vector<vector<int>> zeromatrix(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
    // int row[n]={0}; -> arr[..][0]
    // int col[m]={0}; -> arr[0][..]
    int col0 = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                // mark the i-th row
                arr[i][0] = 0;
                // mark the j-th col 
                if(j != 0)
                    arr[0][j] = 0;
                else 
                    col0 = 0;
            }
        }
    }
    for(int i = 1 ; i<n;i++){
        for(int j = 1 ;j<m;j++){
            if(arr[i][j] != 0){
                // check for col & row
                if(arr[0][j] ==0 || arr[i][0] == 0 ){
                    arr[i][j] = 0 ;
                }
            }
        }
    }
    if(arr[0][0] == 0){
        for(int j =0 ;j<n;j++) arr[0][j] = 0;   
    }
    if(col0 == 0 ){
        for(int i =0;i<n;i++) arr[i][0] = 0;
    }
    return arr;
}
// tc : O(n x m) + O(2 x n x m)
// sc : O(1 variable)  

int main(){
    int n,m;
    cout<<"Enter the size of row : ";
    cin>>n;
    cout<<"Enter the size of col : ";
    cin>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    cout<<"Enter the matrix : "<<endl;
    for(int i = 0;i<n;i++){
        for(int j =0 ;j<m;j++){
            cin>>arr[i][j];
        }
    }
    cout<<endl ;
    cout<<"The original matrix is : "<<endl;
    for(int i = 0;i<n;i++){
        for(int j =0 ;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    cout<<"the set matrix is : "<<endl;
    // set_matrix_zeros(arr);
    zeromatrix(arr);
    for(int i = 0;i<n;i++){
        for(int j =0 ;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}