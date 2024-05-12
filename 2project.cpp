#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareJobs(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
    return a.first.second < b.first.second;
}

vector<int> JobScheduling(int N, vector<pair<pair<int, int>, int>>& Jobs) {
    sort(Jobs.begin(), Jobs.end(), compareJobs);
    vector<bool> timeline(N, false);
    int count = 0;
    int profit = 0;

    for (auto& job : Jobs) {
        for (int i = min(N - 1, job.first.second - 1); i >= 0; --i) {
            if (!timeline[i]) {
                count++;
                profit += job.second;
                timeline[i] = true;
                break;
            }
        }
    }

    return {count, profit};
}

int main() {
    int N = 4;
    vector<pair<pair<int, int>, int>> Jobs = {{{1, 4}, 20}, {{2, 1}, 10}, {{3, 1}, 40}, {{4, 1}, 30}};

    vector<int> result = JobScheduling(N, Jobs);
    cout << "Number of jobs done: " << result[0] << ", Maximum profit: " << result[1] << endl;

    return 0;
}
