#include<bits/stdc++.h>
using namespace std;


// optimal approach
int missingIntegerFrequency(vector<int>& nums) {
        int sequentialSum = nums[0];
        int n = nums.size();
        // max vector size = 50, max sum will occur when full array is
        // sequential -> form =[1,2,3...,50] Sum= n*(n+1)/2=>12575
        vector<bool> freq(1276, 0);
        freq[nums[0]]=1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sequentialSum += nums[i];
                freq[nums[i]] = 1;
            } else {
                while (i < n) {
                    freq[nums[i]] = 1;
                    i++;
                }
            }
        }
        int ans;
        for (int i = sequentialSum; i < 1277; i++) {
            if (freq[i] == 0) {
                ans = i;
                break;
            }
        }
        return ans;
    }

    
// better approach
 int missingIntegerHashSet(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> num_set(nums.begin(), nums.end());
        int total = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                total += nums[i];
            } else {
                break;
            }
        }

        while (num_set.count(total)) {
            total += 1;
        }

        return total;
    }


int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "\nMissing Integer (Frequency Array Approach): " << missingIntegerFrequency(nums) << endl;
    cout << "Missing Integer (Hash Set Approach):        " << missingIntegerHashSet(nums) << endl;

    return 0;
}