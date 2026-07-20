#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ShiftGrid(vector<vector<int>>& grid,int k){
    if(!k) return grid;
    int r = grid.size() , c = grid[0].size();
    int n = r*c;

    k=k%n;
    if(!k) return grid;


    auto shift = [&](int i ,int j ){
        while(i<j){
            swap(grid[i/c][i%c],grid[j/c][j%c]);
            i++;
            j--;
        }
    };

    shift(0,n-1);
    shift(0,k-1);
    shift(k,n-1);
    return grid;
}

int main(){
    int k ;
    cout<<"Enter the value of k number of time to shift : ";
    cin>>k;
    cout<<"Enter the gid matix of 3 x 3 : ";
    vector<vector<int>> grid(3,vector<int>(3));
    for(int i  =0 ;i<3;i++){
        for(int j =0;j<3;j++){
            cin>>grid[i][j];
        }
    }

    cout<<"\n"; 

    ShiftGrid(grid,k);
    for(int i =0 ;i<3;i++){
        for(int j =0;j<3;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}