#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareJobs(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
    return a.first.second < b.first.second;
}

vector<int> JobScheduling(int N, vector<pair<pair<int, int>, int>>& Jobs) {
    sort(Jobs.begin(), Jobs.end(), compareJobs);
    vector<int> dp(N + 1);
    
    for (int i = 1; i <= N; ++i) {
        dp[i] = max(dp[i - 1], Jobs[i - 1].second);
        for (int j = i - 1; j >= 1; --j) {
            if (Jobs[j - 1].first.second <= Jobs[i - 1].first.first) {
                dp[i] = max(dp[i], dp[j] + Jobs[i - 1].second);
                break;
            }
        }
    }
    
    int maxProfit = *max_element(dp.begin(), dp.end());
    int count = 0;
    for (int i = 1; i <= N; ++i) {
        if (dp[i] == maxProfit) {
            count = i;
            break;
        }
    }
    
    return {count, maxProfit};
}

int main() {
    int N = 4;
    vector<pair<pair<int, int>, int>> Jobs = {{{1, 4}, 20}, {{2, 1}, 10}, {{3, 1}, 40}, {{4, 1}, 30}};

    vector<int> result = JobScheduling(N, Jobs);
    cout << "Number of jobs done: " << result[0] << ", Maximum profit: " << result[1] << endl;

    return 0;
}
