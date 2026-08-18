#include <bits/stdc++.h>
using namespace std;


// brute approach
int longestSubsequence(vector<int>& nums) {
    int n = nums.size();
    int totalXor = 0;
    bool allZero = true;

    for (int x : nums) {
        totalXor ^= x;
        if (x > 0) {
            allZero = false;
        }
    }

    if (totalXor > 0) {
        return n;
    }

    return allZero ? 0 : n - 1;
}


// optimal approach
int longestSubsequence(vector<int>& nums) {
        auto tot = 0, nonZero = 0;

        for (auto& n : nums) {
            nonZero |= n > 0;
            tot ^= n;
        }

        return nonZero * (nums.size() - !tot);
    }


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "\nEnter number of elements: ";
        cin >> n;

        vector<int> nums(n);
        cout << "Enter array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        int result = longestSubsequence(nums);
        cout << "Longest subsequence length = " << result << "\n";
    }

    return 0;
}
