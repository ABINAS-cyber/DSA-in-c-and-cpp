#include <bits/stdc++.h>
using namespace std;


bool uniformArray(vector<int>& nums1) {
    int mn = nums1[0];
    bool hasodd = false;
    for (int v : nums1) {
        if (v < mn) {
            mn = v;
        }
        if (v & 1) {
            hasodd = true;
        }
    }
    if (mn & 1) {
        return true;
    }
    return !hasodd;
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums1(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    if (uniformArray(nums1)) {
        cout << "Array is uniform (parity rule satisfied)." << endl;
    } else {
        cout << "Array is NOT uniform." << endl;
    }

    return 0;
}