#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

    int smallestNumber(int n, int t) {
        auto check = [&](int num) -> bool {
            int product = 1;
            while (num) {
                product *= (num % 10);
                num /= 10;
                if (!product) {
                    break;
                }
            }
            return !(product % t);
        };
        while (!check(n)) {
            n++;
        }
        return n;
    }
};


    int main() {
    Solution sol;

    // Test Case 1
    int n1 = 10, t1 = 2;
    cout << "Input: n = " << n1 << ", t = " << t1 << endl;
    cout << "Output: " << sol.smallestNumber(n1, t1) << endl; // Expected: 10

    cout << "--------------------" << endl;

    // Test Case 2
    int n2 = 15, t2 = 3;
    cout << "Input: n = " << n2 << ", t = " << t2 << endl;
    cout << "Output: " << sol.smallestNumber(n2, t2) << endl; // Expected: 16

    return 0;
}