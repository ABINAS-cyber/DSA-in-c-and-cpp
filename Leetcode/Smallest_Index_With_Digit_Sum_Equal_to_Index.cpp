#include <bits/stdc++.h>
using namespace std;


// brute approach
int smallestindex(const vector<int>& nums) {
    auto getDigitSum = [](int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    };

    for (int i = 0; i < nums.size(); ++i) {
        if (getDigitSum(nums[i]) == i) {
            return i;
        }
    }

    return -1;
}



// optimal approach
int smallestIndex(vector<int>& nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
        int res = 0;
        int temp = nums[i]; // keep original intact
        while (temp > 0) {
            res += (temp % 10);
            temp /= 10;
        }
        if (res == i)
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    if (ans.empty())
        return -1;
    else
        return ans[0];
}


int main() {
    int n;
    cin >> n;               
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];     
    }

    int result = smallestIndex(nums);
    cout << result << endl;  

    return 0;
}
