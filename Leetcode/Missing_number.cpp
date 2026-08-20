#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    
    // XOR all numbers from 1 to n
    int xor1 = 0;
    for(int i = 1; i <= n; i++){
        xor1 = xor1 ^ i;
    }

    // XOR all elements present in the array
    int xor2 = 0;
    for(int i = 0; i < n; i++){
        xor2 = xor2 ^ nums[i];
    }

    // The missing number will be the result of xor1 ^ xor2
    return xor1 ^ xor2;
}

int main() {
    // 1. Get the size of the array from the user
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // 2. Read the array elements from the user
    vector<int> nums(n);
    cout << "Enter " << n << " space-separated integers: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // 3. Call the function directly
    int result = missingNumber(nums);

    // 4. Output the result
    cout << "The missing number is: " << result << endl;

    return 0;
}