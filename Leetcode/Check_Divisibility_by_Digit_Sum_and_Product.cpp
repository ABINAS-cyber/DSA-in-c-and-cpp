#include <bits/stdc++.h>
using namespace std;

bool checkDivisibility(int n) {
    int digitSum = 0;
    int digitProduct = 1;
    int original = n;

    while (n > 0) {
        int digit = n % 10;
        n /= 10;

        digitSum += digit;
        digitProduct *= digit;
    }
    return original % (digitSum + digitProduct) == 0;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (checkDivisibility(n)) {
        cout << n << " is divisible by the sum + product of its digits." << endl;
    } else {
        cout << n << " is NOT divisible by the sum + product of its digits." << endl;
    }

    return 0;
}