#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    unordered_map<int, vector<int>> graph;
    int ans = 0;

    while (getline(cin, str)) {
        if (str.empty()) break;

        size_t delimiterPos = str.find('|');
        int first = stoi(str.substr(0, delimiterPos));
        int second = stoi(str.substr(delimiterPos + 1));

        graph[first].emplace_back(second);
    }

    while (getline(cin, str)) {
        set<int> nums;
        stringstream ss(str);
        string token;

        while (getline(ss, token, ',')) {
            nums.insert(stoi(token));
        }

		
    }

    cout << ans << endl;

    return 0;
}