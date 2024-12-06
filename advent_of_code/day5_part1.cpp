#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    unordered_map<int, vector<int>> order;
    int ans = 0;

    while (getline(cin, str)) {
        if (str.empty()) break;

        size_t delimiterPos = str.find('|');
        int first = stoi(str.substr(0, delimiterPos));
        int second = stoi(str.substr(delimiterPos + 1));

        order[first].emplace_back(second);
    }

    while (getline(cin, str)) {
        vector<int> nums;
        stringstream ss(str);
        string token;

        while (getline(ss, token, ',')) {
            nums.emplace_back(stoi(token));
        }

        unordered_map<int, int> pos;
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]] = i;
        }

        bool ok = true;
        for (int key : nums) {
            if (order.find(key) != order.end()) {
                int keyPos = pos[key];

                for (int sec : order[key]) {
                    if (pos.find(sec) != pos.end()) {
                        int secPos = pos[sec];
                        if (secPos <= keyPos) {
                            ok = false;
                            break;
                        }
                    }
                }
            }

            if (!ok) break;
        }

        if (ok) ans += nums[nums.size() / 2];
    }

    cout << ans << endl;

    return 0;
}