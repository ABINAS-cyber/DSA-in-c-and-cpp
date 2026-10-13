#include<bits/stdc++.h>
using namespace std;

int kthelement(vector<int>& nums1,vector<int>& nums2,int k ){
     int n1 = nums1.size();
    int n2 = nums2.size();
    if (n1 > n2) return kthelement(nums2, nums1,k);
    int low = max(0,k-n2), high = min(k,n1);
    int left = k;
    int n = n1 + n2;
    while (low <= high) {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = nums1[mid1];
        if (mid2 < n2) r2 = nums2[mid2];
        if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }
    return -1;
}


int main() {
    int n1, n2, k;
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> nums1(n1);
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < n1; i++) cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> nums2(n2);
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < n2; i++) cin >> nums2[i];

    cout << "Enter k (1-based index): ";
    cin >> k;

    int ans = kthelement(nums1, nums2, k);
    cout << "The " << k << "-th element is: " << ans << endl;

    return 0;
}