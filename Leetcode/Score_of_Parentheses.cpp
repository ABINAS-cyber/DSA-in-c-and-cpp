#include <bits/stdc++.h>
using namespace std;

int scoreOfParentheses(string s) {
    int depth = 0, score = 0, n = s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            depth++;
        } else {
            depth--;
            if (s[i - 1] == '(') {
                score += 1 << depth;
            }
        }
    }
    return score;
}

int main() {
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    cout << "Score: " << scoreOfParentheses(s) << endl;
    return 0;
}
