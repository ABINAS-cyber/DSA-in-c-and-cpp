#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0b11110000;   // seats 2–5
        int middle = 0b11000011; // seats 4–7
        int right = 0b00001111;  // seats 6–9

        unordered_map<int, int> occupied;
        for (const vector<int>& seat : reservedSeats) {
            if (seat[1] >= 2 && seat[1] <= 9) {
                occupied[seat[0]] |= (1 << (seat[1] - 2));
            }
        }

        int ans = (n - occupied.size()) * 2;
        for (auto& entry : occupied) {
            int row = entry.first;
            int bitmask = entry.second;

            if (((bitmask | left) == left) || 
                ((bitmask | middle) == middle) || 
                ((bitmask | right) == right)) {
                ++ans;
            }
        }
        return ans;
    }
};


/*
Enter number of rows: 3
Enter number of reserved seats: 3
Enter reserved seats (row seat):
1 2
1 3
2 6
Maximum number of families that can be seated: 4

*/


int main() {
    int n, m;
    cout << "Enter number of rows: ";
    cin >> n;

    cout << "Enter number of reserved seats: ";
    cin >> m;

    vector<vector<int>> reservedSeats(m, vector<int>(2));
    cout << "Enter reserved seats (row seat):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> reservedSeats[i][0] >> reservedSeats[i][1];
    }

    Solution sol;
    int result = sol.maxNumberOfFamilies(n, reservedSeats);

    cout << "Maximum number of families that can be seated: " << result << endl;

    return 0;
}