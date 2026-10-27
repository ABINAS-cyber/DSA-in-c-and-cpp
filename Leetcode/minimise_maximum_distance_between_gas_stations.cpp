#include <bits/stdc++.h>
using namespace std;

// brute force approach
long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();

    vector<int> howmany(n - 1, 0);

    for (int gasstations = 1; gasstations <= k; gasstations++) {
        int maxind = -1;
        long double maxsection = -1;

        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionlength = diff / (long double)(howmany[i] + 1);

            if (sectionlength > maxsection) {
                maxsection = sectionlength;
                maxind = i;
            }
        }

        howmany[maxind]++;
    }

    long double maxans = -1;

    for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double sectionlength =
            diff / (long double)(howmany[i] + 1);

        maxans = max(maxans, sectionlength);
    }

    return maxans;
}
// tc :  O(k * n) 
// sc : O( n )






int main() {
    int n;
    cout << "Enter number of gas stations: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter positions of gas stations: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter number of new gas stations to add: ";
    cin >> k;

    cout << fixed << setprecision(6);
    cout << "Minimum possible maximum distance = "
         << minimiseMaxDistance(arr, k) << endl;

    return 0;
}
