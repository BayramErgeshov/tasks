#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMedian(vector<int> arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    if (n % 2 == 0) {
        return (double)(arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else {
        return (double)arr[n / 2];
    }
}

int main() {
    string choice;
    do {
        vector<int> arr = { 1, 2, 3, 4, 5 };
        cout << "Median is: " << findMedian(arr) << endl;
        cout << "Run again? (y/n): ";
        cin >> choice;
    } while (choice == "y" || choice == "Y");
    return 0;
}