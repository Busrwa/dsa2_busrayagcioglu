#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxChainLen(vector<pair<int, int>>& P, int N) {
    sort(P.begin(), P.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    vector<int> dp(N, 1);

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (P[i].first > P[j].second && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int N = 5;
    vector<pair<int, int>> P = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};

    cout << "Length of longest chain: " << maxChainLen(P, N) << endl;

    return 0;
}
