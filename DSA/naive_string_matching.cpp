#include<bits/stdc++.h>

using namespace std;

void naive_string_matching(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    for (int s = 0; s <= n - m; s++) {
        int i;
        for (i = 0; i < m; i++) {
            if (text[s + i] != pattern[i]) {
                break;
            }
        }
        if (i == m) {
            cout << "Pattern found at index: " << s << endl;
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    naive_string_matching(text, pattern);
    cout << "Naive string matching completed." << endl;

    return 0;
}