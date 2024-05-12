#include <iostream>
#include <vector>
using namespace std;

int numberSequence(int m, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i][j - 1] + dp[i / 2][j];
        }
    }

    return dp[n][m];
}

int main() {
    int m1 = 10, n1 = 4;
    cout << numberSequence(m1, n1) << endl;

    int m2 = 5, n2 = 2;
    cout << numberSequence(m2, n2) << endl;

    return 0;
}
