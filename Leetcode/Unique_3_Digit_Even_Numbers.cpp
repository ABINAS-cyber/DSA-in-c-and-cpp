#include<bits/stdc++.h>
using namespace std;


int totalNumbers(vector<int>& digits) {
    int n = digits.size();
    bool vis[1000]{};
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (digits[i] == 0) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (j == i) {
                continue;
            }
            for (int k = 0; k < n; ++k) {
                if (k == i || k == j || digits[k] % 2 != 0) {
                    continue;
                }
                int x = digits[i] * 100 + digits[j] * 10 + digits[k];
                if (!vis[x]) {
                    vis[x] = true;
                    ++ans;
                }
            }
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of digits: ";
    cin >> n;

    vector<int> digits(n);
    cout << "Enter the digits: ";
    for (int i = 0; i < n; ++i) {
        cin >> digits[i];
    }

    int result = totalNumbers(digits);
    cout << "Total unique 3-digit numbers formed: " << result << endl;

    return 0;
}