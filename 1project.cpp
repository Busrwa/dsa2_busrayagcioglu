#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareMeetings(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int maxMeetings(int N, vector<int>& start, vector<int>& end) {
    vector<pair<int, int>> meetings;
    for (int i = 0; i < N; ++i) {
        meetings.push_back({start[i], end[i]});
    }
    sort(meetings.begin(), meetings.end(), compareMeetings);
    
    int count = 1;
    int prev_end = meetings[0].second;

    for (int i = 1; i < N; ++i) {
        if (meetings[i].first > prev_end) {
            count++;
            prev_end = meetings[i].second;
        }
    }

    return count;
}

int main() {
    int N = 6;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << "Maximum number of meetings: " << maxMeetings(N, start, end) << endl;

    return 0;
}
