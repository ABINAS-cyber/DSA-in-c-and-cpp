#include<bits/stdc++.h>
using namespace std;




vector<int> spiral_matrix(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
    int left = 0 , right = m-1;
    int top =  0 , bottom = n-1;
    vector<int> ans;
    
    while(top<=bottom && left<= right){
        // right 
        for(int i=left;i<=right;i++){
            ans.push_back(arr[top][i]);
        }
        top++;

        // bottom 
        for(int i = top ; i <= bottom;i++){
            ans.push_back(arr[i][right]);
        }
        right--;

        // left 
        if(top <= bottom){
            for(int i = right ; i>=left;i--){
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        // top 
        if(left <= right){
            for(int i=bottom ;i >= top;i--){
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }
    return ans;
}
// tc : O(n x m)
// sc : O(n x m) 




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


    spiral_matrix(arr);



    vector<int> spiral_order = spiral_matrix(arr);

    // FIX: Print the 1D vector instead of the 2D matrix
    cout << "The spiral matrix is : " << endl;
    for(int i = 0; i < spiral_order.size(); i++){
        cout << spiral_order[i] << " ";
    }
    cout << endl;
    return 0;
}
