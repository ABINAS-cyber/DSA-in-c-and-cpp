#include <bits/stdc++.h>
using namespace std;

// brute force approach
int func(vector<int>& arr, int pages) {
    int stu = 1, pagestudent = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (pagestudent + arr[i] <= pages) {
            pagestudent += arr[i];
        } else {
            stu++;
            pagestudent = arr[i];
        }
    }
    return stu;
}

int bookallocation(vector<int>& arr, int m) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    for (int pages = low; pages <= high; pages++) {
        int cntstu = func(arr, pages);
        if (cntstu == m) {
            return pages;
        }
    }
    return low;
}
// tc : O(sum - max) x O(N)
// sc : O(1)


// optimal appraoch
int countstudents(vector<int>& arr,int pages){
    int students = 1;
    long long pagestudent = 0;
    int n = arr.size();
    for(int i = 0;i<n;i++){
        if(pagestudent + arr[i] <= pages){
            pagestudent += arr[i];
        }else{
            students +=1;
            pagestudent +=arr[i];
        }
    } 
    return students;
}

int findpages(vector<int>& arr ,int m){
    int n = arr.size();
    if(m>n) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    while(low <= high){
        int mid = (low + high)/2;
        int students = countstudents(arr,mid);
        if(students > m){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low;
}
// tc: O(log2(sum - max + 1) x O(N))
// sc : O(1)


int main() {
    int n, m;
    cout << "Enter number of books: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter pages in each book: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter number of students: ";
    cin >> m;

    // int result = bookallocation(arr, m);
    int result = findpages(arr,m);
    cout << "Minimum possible maximum pages = " << result << endl;

    return 0;
}
