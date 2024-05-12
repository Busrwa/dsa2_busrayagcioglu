#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<int>>& graph, vector<int>& colors, int v, int c) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] == 1 && colors[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& colors, int v) {
    if (v == graph.size()) {
        return true;
    }

    for (int c = 1; c <= m; ++c) {
        if (isValid(graph, colors, v, c)) {
            colors[v] = c;
            if (graphColoringUtil(graph, m, colors, v + 1)) {
                return true;
            }
            colors[v] = 0;
        }
    }

    return false;
}

int graphColoring(vector<vector<int>>& graph, int m) {
    vector<int> colors(graph.size(), 0);
    if (graphColoringUtil(graph, m, colors, 0)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int M = 3;
    cout << graphColoring(graph, M) << endl; // Output: 1

    return 0;
}
