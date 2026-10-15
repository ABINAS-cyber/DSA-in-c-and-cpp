#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            for (int j = i; j < n; j++) {
                s.insert(nums[j]);
                res += s.size() * s.size();
            }
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;  // number of elements

    unordered_set<int> us;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        us.insert(x);  // insert into unordered_set
    }

    // convert unordered_set to vector
    vector<int> nums(us.begin(), us.end());

    Solution sol;
    cout << sol.sumCounts(nums) << endl;

    return 0;
}
