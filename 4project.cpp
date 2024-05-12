#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparePairs(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int maxChainLen(vector<pair<int, int>>& P, int N) {
    sort(P.begin(), P.end(), comparePairs);
    int count = 1;
    int prev_end = P[0].second;

    for (int i = 1; i < N; ++i) {
        if (P[i].first > prev_end) {
            count++;
            prev_end = P[i].second;
        }
    }

    return count;
}

int main() {
    int N = 5;
    vector<pair<int, int>> P = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};

    cout << "Length of longest chain: " << maxChainLen(P, N) << endl;

    return 0;
}
