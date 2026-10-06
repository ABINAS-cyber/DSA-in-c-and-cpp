#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
    int ob = 0;   // open bracket count
    int mar = 0;  // missing bracket count

    for (char c : s) {
        if (c == '(') {
            ob++;
        } else {
            ob > 0 ? ob-- : mar++;
        }
    }
    return mar + ob;
}

int main() {
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    cout << "Minimum additions needed: " << minAddToMakeValid(s) << endl;
    return 0;
}
