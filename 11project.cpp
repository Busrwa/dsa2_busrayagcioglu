#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int curr_min) {
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > curr_min)
            return false;

        if (curr_sum + arr[i] > curr_min) {
            studentsRequired++;
            curr_sum = arr[i];

            if (studentsRequired > m)
                return false;
        } else {
            curr_sum += arr[i];
        }
    }
    return true;
}

int findPages(vector<int>& arr, int n, int m) {
    long long sum = 0;

    if (n < m)
        return -1;

    for (int i = 0; i < n; ++i)
        sum += arr[i];

    int low = 0, high = sum, result = INT_MAX;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = min(result, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 2;

    cout << findPages(arr, n, m) << endl;

    return 0;
}
