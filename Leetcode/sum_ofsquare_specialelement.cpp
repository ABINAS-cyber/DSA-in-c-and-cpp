#include <bits/stdc++.h>
using namespace std;

int sumOfSquares(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            ans += nums[i - 1] * nums[i - 1];
            if (i * i != n) {
                ans += nums[n / i - 1] * nums[n / i - 1];
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Sum of squares: " << sumOfSquares(nums) << endl;
    return 0;
}
