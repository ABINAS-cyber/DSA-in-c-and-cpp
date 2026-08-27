#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int missingMultiple(vector<int>& nums, int k) {
//         vector<bool> freq(101, 0);
        
//         for(int i = 0; i < nums.size(); i++)
//             freq[nums[i]] = 1;
            
//         int i = k;
//         while(i <= 100) {
//             if(!freq[i])
//                 return i;
//             i += k;
//         }
//         return ((100 / k) + 1) * k;
//     }
// };


class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> freq(101,0);

        for(int i=0;i<nums.size();i++)
        freq[nums[i]] = 1;

        int i = k;
        while(i <= 100) {
            if(!freq[i])
            return i;
            i += k;
        }
        return ((100 / k) + 1) * k;
    }
};

int main() {
    int n, k;
    
    // 1. Get the size of the array
    cout << "Enter the number of elements in the array: ";
    if (!(cin >> n)) {
        cout << "Invalid input." << endl;
        return 1;
    }
    
    // 2. Get the array elements
    vector<int> nums(n);
    cout << "Enter the " << n << " elements (values should be <= 100 based on array size): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // 3. Get the multiplier 'k'
    cout << "Enter the value of k: ";
    cin >> k;
    
    // 4. Instantiate the solution and call the function
    Solution obj;
    int result = obj.missingMultiple(nums, k);
    
    // 5. Output the result
    cout << "The first missing multiple of " << k << " is: " << result << endl;
    
    return 0;
}