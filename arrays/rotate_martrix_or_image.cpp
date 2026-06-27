#include<bits/stdc++.h>
using namespace std;


// brute approach
vector<vector<int>> rotate_matrix(vector<vector<int>> &arr){
int n = arr.size();
int m = arr[0].size();
vector<vector<int>> ans(n,vector<int>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        ans[j][n-1-i] = arr[i][j];
    }
}
return arr = ans;
}
// tc : O(n^2)
// sc : O(n^2)



// optimal approach 
void Rotate_Matrix(vector<vector<int>> &arr){
    int n = arr.size();
    // transpose
    // O(N/2 * N/2)
    for(int i = 0 ;i<=n-2;i++){
        for(int j = i+1;j<=n-1;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
    // reverse
    // O(N * N/2)
    for(int i=0 ;i<n;i++){
        reverse(arr[i].begin(),arr[i].end()); // in place of reverse function
        // we can write the code
    }
}
// tc : O(N/2 * N/2) + O(N * N/2)
// sc : O(1)



// O(N/2)
void reverse_matrix(vector<vector<int>> &arr){
    int n = arr.size();
    int p1 = 0 , p2 = n-1;
    while(p1<p2){
        swap(arr[p1],arr[p2]);
        p1++ ; p2-- ;
    }
    // return array
}



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


    // rotate_matrix(arr);
    Rotate_Matrix(arr);


    for(int i = 0;i<n;i++){
        for(int j =0 ;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
