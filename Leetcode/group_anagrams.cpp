#include<bits/stdc++.h>
using namespace std;


// using sorting 
vector<vector<string>> groupanagram(vector<string>  words){

    map<string,vector<string>> group;

    for(string word : words){
        string key = word;
        sort(key.begin(),key.end());
        group[key].push_back(word);
    }

    vector<vector<string>> ans;
    for(auto it : group ){
        ans.push_back(it.second);
    }
    return ans;
}


// using without sorting 
vector<vector<string>> groupanagrams(vector<string> words) {
    // map from frequency signature -> list of words
    unordered_map<string, vector<string>> group;
    for (string word : words) {
        // build frequency signature
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        // convert frequency vector into a string key
        string key;
        for (int f : freq) {
            key += "#" + to_string(f);  // ensures uniqueness
        }

        group[key].push_back(word);
    }
    // collect results
    vector<vector<string>> ans;
    for (auto &it : group) {
        ans.push_back(it.second);
    }
    return ans;
}



// using without sorting and map 
// Function to compute frequency signature
vector<int> getSignature(const string &word) {
    vector<int> freq(26, 0);
    for (char c : word) {
        freq[c - 'a']++;
    }
    return freq;
}

vector<vector<string>> groupAnagrams(vector<string> &words) {
    vector<vector<string>> groups;          // final groups
    vector<vector<int>> signatures;         // signatures for each group

    for (string &word : words) {
        vector<int> sig = getSignature(word);
        bool placed = false;

        // check existing groups
        for (int i = 0; i < signatures.size(); i++) {
            if (signatures[i] == sig) {     // found matching signature
                groups[i].push_back(word);
                placed = true;
                break;
            }
        }
        // if no match, create new group
        if (!placed) {
            groups.push_back({word});
            signatures.push_back(sig);
        }
    }
    return groups;
}


int main() {

    int n;
    cout << "Enter number of words: ";
    cin >> n;

    vector<string> str(n);

    cout << "Enter the words: ";
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    vector<vector<string>> ans = groupanagrams(str);

    cout << "Grouped Anagrams:\n";

    for (auto group : ans) {
        cout << "[ ";
        for (string word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
    return 0;
}