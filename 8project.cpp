#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(string s) {
    if (s.length() > 1 && s[0] == '0')
        return false;
    int num = stoi(s);
    return num >= 0 && num <= 255;
}

void generateIP(string S, int idx, int parts, string temp, vector<string>& result) {
    if (idx == S.length() && parts == 4) {
        result.push_back(temp);
        return;
    }

    if (idx == S.length() || parts == 4)
        return;

    for (int len = 1; len <= 3 && idx + len <= S.length(); ++len) {
        string part = S.substr(idx, len);
        if (isValid(part)) {
            if (idx == 0)
                generateIP(S, idx + len, parts + 1, part, result);
            else
                generateIP(S, idx + len, parts + 1, temp + "." + part, result);
        }
    }
}

vector<string> genIp(string S) {
    vector<string> result;
    generateIP(S, 0, 0, "", result);
    return result;
}

int main() {
    string S = "1111";
    vector<string> result = genIp(S);

    if (result.empty())
        cout << "-1" << endl;
    else
        for (const auto& ip : result)
            cout << ip << endl;

    return 0;
}
