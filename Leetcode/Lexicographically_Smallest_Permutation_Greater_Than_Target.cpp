#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
            cnt[target[i] - 'a']--;
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            int b = target[i] - 'a';
            cnt[b]++;  
            if (*min_element(cnt.begin(), cnt.end()) < 0) {
                continue;
            }

            for (int j = b + 1; j < 26; j++) {
                if (cnt[j]) {
                    cnt[j]--;
                    target[i] = 'a' + j;
                    target.resize(i + 1);
                    return target + getMinString(cnt);
                }
            }
        }

        return "";
    }

    string getMinString(const vector<int>& cnt) {
        string res;
        for (int i = 0; i < 26; i++) {
            res.append(cnt[i], 'a' + i);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s, target;

    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter target string: ";
    cin >> target;

    string result = sol.lexGreaterPermutation(s, target);

    if (result.empty()) {
        cout << "No lexicographically greater permutation exists." << endl;
    } else {
        cout << "Result: " << result << endl;
    }

    return 0;
}