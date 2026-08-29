#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        for (int m = k; m <= s.length(); m++) {
            string ans = "";
            for (int i = m; i <= s.length(); i++) {
                string t = s.substr(i - m, m);
                // use std::count instead of ranges::count
                if ((ans.empty() || t < ans) && count(t.begin(), t.end(), '1') == k) {
                    ans = t;
                }
            }
            if (!ans.empty()) {
                return ans;
            }
        }
        return "";
    }
};

int main() {
    Solution sol;
    string s;
    int k;

    cout << "Enter the binary string: ";
    cin >> s;
    cout << "Enter k (number of '1's required): ";
    cin >> k;

    string result = sol.shortestBeautifulSubstring(s, k);

    if (result.empty()) {
        cout << "No valid substring found." << endl;
    } else {
        cout << "Shortest beautiful substring: " << result << endl;
    }

    return 0;
}
