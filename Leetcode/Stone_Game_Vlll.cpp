#include <bits/stdc++.h>
using namespace std;

int stoneGameVIII(vector<int>& stones) {
    int n = stones.size();
    vector<int> pre;
    partial_sum(stones.begin(), stones.end(), back_inserter(pre));
    vector<int> f(n);
    f[n - 1] = pre[n - 1];
    for (int i = n - 2; i >= 1; --i) {
        f[i] = max(f[i + 1], pre[i] - f[i + 1]);
    }
    return f[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Enter number of stones: ";
    cin >> n;

    vector<int> stones(n);
    cout << "Enter stone values: ";
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    int result = stoneGameVIII(stones);
    cout << "Result of Stone Game VIII: " << result << "\n";

    return 0;
}
