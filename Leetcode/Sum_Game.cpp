#include <bits/stdc++.h>
using namespace std;

/*
bool sumGame(string num) {
    int n = num.size();

    auto get = [](string s) -> pair<int, int> {
        int nn = 0, qq = 0;
        for (char ch : s) {
            if (ch == '?') {
                ++qq;
            } else {
                nn += (ch - '0');
            }
        }
        return {nn, qq};
    };

    auto [n0, q0] = get(num.substr(0, n / 2));
    auto [n1, q1] = get(num.substr(n / 2, n / 2));

    return ((q0 + q1) % 2 == 1) || (n0 - n1 != (q1 - q0) * 9 / 2);
}
*/



bool sumGame(string num) {
    int n = num.size();

    auto get = [](string s) -> pair<int, int> {
        int nn = 0, qq = 0;
        for (char ch : s) {
            if (ch == '?') {
                ++qq;
            } else {
                nn += (ch - '0');
            }
        }
        return make_pair(nn, qq);
    };

    pair<int,int> leftPart = get(num.substr(0, n / 2));
    pair<int,int> rightPart = get(num.substr(n / 2, n / 2));

    int n0 = leftPart.first;
    int q0 = leftPart.second;
    int n1 = rightPart.first;
    int q1 = rightPart.second;

    return ((q0 + q1) % 2 == 1) || (n0 - n1 != (q1 - q0) * 9 / 2);
}

int main() {
    string num;
    cout << "Enter the numeric string with '?' characters: ";
    cin >> num;

    bool result = sumGame(num);

    if (result) {
        cout << "Alice wins the game!" << endl;
    } else {
        cout << "Bob wins the game!" << endl;
    }

    return 0;
}



/*
Example 1:

Input: num = "5023"
Output: false
Explanation: There are no moves to be made.
The sum of the first half is equal to the sum of the second half: 5 + 0 = 2 + 3.

Example 2:

Input: num = "25??"
Output: true
Explanation: Alice can replace one of the '?'s with '9' and it will be impossible for Bob to make the sums equal.

Example 3:

Input: num = "?3295???"
Output: false
Explanation: It can be proven that Bob will always win. One possible outcome is:
- Alice replaces the first '?' with '9'. num = "93295???".
- Bob replaces one of the '?' in the right half with '9'. num = "932959??".
- Alice replaces one of the '?' in the right half with '2'. num = "9329592?".
- Bob replaces the last '?' in the right half with '7'. num = "93295927".
Bob wins because 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7.
*/



int main() {
    string num;
    cout << "Enter the numeric string with '?' characters: ";
    cin >> num;

    bool result = sumGame(num);

    if (result) {
        cout << "Alice wins the game!" << endl;
    } else {
        cout << "Bob wins the game!" << endl;
    }
    return 0;
}