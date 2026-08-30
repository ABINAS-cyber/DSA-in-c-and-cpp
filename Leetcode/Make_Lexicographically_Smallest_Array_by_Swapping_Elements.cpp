#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());
        
        int currGroup = 0;
        unordered_map<int, int> numToGroup;
        numToGroup.insert({numsSorted[0], currGroup});

        unordered_map<int, list<int>> groupToList;
        groupToList.insert({currGroup, list<int>(1, numsSorted[0])});

        for (int i = 1; i < nums.size(); i++) {
            if (abs(numsSorted[i] - numsSorted[i - 1]) > limit) {
                currGroup++;
            }

            numToGroup.insert({numsSorted[i], currGroup});

            if (groupToList.find(currGroup) == groupToList.end()) {
                groupToList[currGroup] = list<int>();
            }
            groupToList[currGroup].push_back(numsSorted[i]);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int group = numToGroup[num];
            nums[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }

        return nums;
    }
};

int main() {
    Solution sol;
    int n, limit;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter limit: ";
    cin >> limit;

    vector<int> result = sol.lexicographicallySmallestArray(nums, limit);

    cout << "Lexicographically smallest array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
