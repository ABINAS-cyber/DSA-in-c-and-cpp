#include <bits/stdc++.h>
using namespace std;

// Helper function: count how many painters (splits) are needed
int reqpainters(vector<int>& arr, int mid) {
    int noofpainters = 1;
    int currsum = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (currsum + arr[i] <= mid) {
            currsum += arr[i];
        } else {
            noofpainters++;
            currsum = arr[i];
        }
    }
    return noofpainters;
}

// Main function: binary search for minimum largest sum
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high) {
        int mid = (low + high) / 2;
        int no_painter = reqpainters(nums, mid);

        if (no_painter > k) {
            low = mid + 1;   // need more capacity
        } else {
            high = mid - 1;  // try smaller capacity
        }
    }
    return low;
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter number of painters (splits): ";
    cin >> k;

    int result = splitArray(nums, k);
    cout << "Minimum largest sum after splitting: " << result << endl;

    return 0;
}
