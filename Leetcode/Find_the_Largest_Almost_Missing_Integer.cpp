#include<bits/stdc++.h>
using namespace std;


int largestInteger(vector<int>& nums, int k) {
    int n = nums.size();
    if (n == k) {
        return *max_element(nums.begin(), nums.end());
    }
    int count[51] = {0};
    for (int x : nums) {
        count[x]++;
    }
    if (k == 1) {
        for (int i = 50; i >= 0; --i) {
            if (count[i] == 1) {
                return i;
            }
        }
        return -1;
    }
    int res = -1;
    if (count[nums[0]] == 1) {
        res = max(res, nums[0]);
    }
    if (count[nums.back()] == 1) {
        res = max(res, nums.back());
    }
    return res;
}


int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    // Call the function directly
    int result = largestInteger(nums, k);
    
    cout << "Largest almost missing integer: " << result << endl;

    return 0;
}