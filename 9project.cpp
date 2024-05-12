#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

bool isSafe(int x, int y, int R, int C) {
    return (x >= 0 && x < R && y >= 0 && y < C);
}

void findWordsUtil(vector<vector<char>>& board, int x, int y, int R, int C, string& str, unordered_set<string>& dictionary, unordered_set<string>& result, vector<vector<bool>>& visited) {
    visited[x][y] = true;
    str.push_back(board[x][y]);

    if (dictionary.find(str) != dictionary.end())
        result.insert(str);

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int newX = x + i;
            int newY = y + j;

            if (isSafe(newX, newY, R, C) && !visited[newX][newY]) {
                findWordsUtil(board, newX, newY, R, C, str, dictionary, result, visited);
            }
        }
    }

    visited[x][y] = false;
    str.pop_back();
}

vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
    int R = board.size();
    int C = board[0].size();
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    unordered_set<string> result;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            string str = "";
            findWordsUtil(board, i, j, R, C, str, dict, result, visited);
        }
    }

    vector<string> res(result.begin(), result.end());
    return res;
}

int main() {
    vector<vector<char>> board = {{'G', 'I', 'Z'},
                                   {'U', 'E', 'K'},
                                   {'Q', 'S', 'E'}};
    vector<string> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};

    vector<string> words = wordBoggle(board, dictionary);

    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
