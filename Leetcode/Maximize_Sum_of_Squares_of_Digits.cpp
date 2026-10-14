#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        int r = sum % 9;
        string ans(sum / 9, '9');
        if (r > 0) {
            ans.push_back('0' + r);
        }
        ans.append(num - (int)ans.size(), '0');
        return ans;
    }
};

int main() {
    int num, sum;
    cout << "Enter number of digits: ";
    cin >> num;
    cout << "Enter sum: ";
    cin >> sum;

    Solution sol;
    string result = sol.maxSumOfSquares(num, sum);

    if (result.empty()) {
        cout << "Not possible to form such a number." << endl;
    } else {
        cout << "Result: " << result << endl;
    }

    return 0;
}
