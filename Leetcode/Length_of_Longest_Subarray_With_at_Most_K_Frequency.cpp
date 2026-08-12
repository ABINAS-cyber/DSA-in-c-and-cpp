#include<bits/stdc++.h>
using namespace std;

int maxSubarrayLength(vector<int>& nums, int k) {
    int ans = 0, start = -1;
    unordered_map<int, int> frequency;
    
    for (int end = 0; end < nums.size(); end++) {
        frequency[nums[end]]++;
        while (frequency[nums[end]] > k) {
            start++;
            frequency[nums[start]]--;
        }
        ans = max(ans, end - start);
    }   
    return ans;
}

int main() {
    int n, k;

    cout << "Enter the number of elements in the array: ";
    if (!(cin >> n) || n <= 0) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    vector<int> nums(n);
    cout << "Enter " << n << " integers separated by spaces: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = maxSubarrayLength(nums, k);

    cout << "Length of longest good subarray: " << result << endl;

    return 0;
}