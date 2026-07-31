#include<bits/stdc++.h>
using namespace std;


// based on image
// Input: word = "abcde"
// Output: 5
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// Total cost is 1 + 1 + 1 + 1 + 1 = 5.
// It can be shown that no other mapping can provide a lower cost.



int minimumPushes(string word) {
        // Frequency vector to store count of each letter
        vector<int> frequency(26, 0);

        // Count occurrences of each letter
        for (char& c : word) {
            ++frequency[c - 'a'];
        }

        // Sort frequencies in descending order
        sort(frequency.rbegin(), frequency.rend());

        int totalPushes = 0;

        // Calculate total number of presses
        for (int i = 0; i < 26; ++i) {
            if (frequency[i] == 0) break;
            totalPushes += (i / 8 + 1) * frequency[i];
        }

        return totalPushes;
    }


int main(){
    string s;
    cout<<"Enter the string : ";
    getline(cin,s);
    cout<<"The minimum pushes are  : "<<minimumPushes(s);
    return 0;
}