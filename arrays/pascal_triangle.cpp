#include<bits/stdc++.h>
using namespace std;


// ==========================================
// 1 Variety Question 
// ==========================================
// Given R & C tell the element at that place 
// n = row - 1, r = col - 1 
int NcR (int n, int r){
    long long res = 1;
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res /= (i + 1);
    }
    return res;
}
// tc : O(r)
// sc : O(1)


// ==========================================
// 2 Variety Question 
// ==========================================
// Print any N row of pascal triangle

// Brute force approach 
void generateNRow(int n){
    for(int c = 1; c <= n; c++){
        cout << NcR(n - 1, c - 1) << " "; 
    }
    cout << endl;
}


// Optimized approach
vector<int> generateNthRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col = 1 ; col < row; col++) {
        ans = ans * (row - col);
        ans /= col;
        ansRow.push_back(ans);
    }
    return ansRow;
}


// ==========================================
// 3 Variety Question
// ==========================================
// Given N , print the entire triangle

// Naive brute approach 
vector<vector<int>> print_entire_pascal(int n){
    vector<vector<int>> ans;
    for(int row = 1 ; row <= n; row++){
        vector<int> templis;
        for(int col = 1 ; col <= row; col++){
            templis.push_back(NcR(row - 1, col - 1));
        }
        ans.push_back(templis);
    }
    return ans;
}


// Optimized approach
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col = 1 ; col < row; col++) {
        ans = ans * (row - col);
        ans /= col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
 

vector<vector<int>> pascalTriangle(int N){
    vector<vector<int>> ans;
    for(int i = 1; i <= N; i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}



// or else we can make it one function
vector<vector<int>> pascaltriangle(int N) {
    vector<vector<int>> ansl;
    int row = N;
    for(int i = 1;i<=N;i++) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col = 1;col<row;col++) {
            ans = ans * (row - col);
            ans = ans / (col);
            ansRow.push_back(ans);
        }
        ansl.push_back(ansRow);
    }
    return ansl;
}






// ==========================================
// Main Function with User Input
// ==========================================
int main() {
    int R, C, nthRow, totalRows;

    // --- Variety 1 ---
    cout << "--- Variety 1: Find Element at (R, C) ---" << endl;
    cout << "Enter Row (R): ";
    cin >> R;
    cout << "Enter Column (C): ";
    cin >> C;
    // Check for valid bounds roughly
    if (C > R || R < 1 || C < 1) {
        cout << "Invalid position! Column cannot be greater than Row, and both must be >= 1." << endl;
    } else {
        cout << "Element at Row " << R << ", Col " << C << " is: " << NcR(R - 1, C - 1) << endl; 
    }
    cout << "\n";

    // --- Variety 2 ---
    cout << "--- Variety 2: Print the Nth Row ---" << endl;
    cout << "Enter the row number you want to print: ";
    cin >> nthRow;
    
    cout << "Brute Force Output: ";
    generateNRow(nthRow);
    
    cout << "Optimized Output:   ";
    vector<int> rowResult = generateNthRow(nthRow);
    for(int val : rowResult) {
        cout << val << " ";
    }
    cout << "\n\n";

    // --- Variety 3 ---
    cout << "--- Variety 3: Print Entire Triangle up to N Rows ---" << endl;
    cout << "Enter the total number of rows: ";
    cin >> totalRows;
    
    cout << "\nPascal's Triangle:" << endl;
    // Using the optimized version to print the triangle
    vector<vector<int>> fullTriangle = pascalTriangle(totalRows);
    for(int i = 0; i < fullTriangle.size(); i++) {
        for(int j = 0; j < fullTriangle[i].size(); j++) {
            cout << fullTriangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}