#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> v;
    string str;

    while (getline(cin, str)) {
        v.push_back(str);
    }

    int n = v.size();
    int m = v[0].size();

    vector<vector<int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

    int ans = 0;
	string target = "XMAS";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = v[i][j];

            if (c == 'X') {
                for (auto d : dir) {
                    string temp(1, c);

                    for (int k = 1; k <= 3; k++) {
                        int rd = i + k * d[0];
                        int cd = j + k * d[1];

                        if (rd < 0 || cd < 0 || rd >= n || cd >= m || v[rd][cd] != target[k]) {
                            break;
                        }

                        temp += v[rd][cd];
                    }

                    if (temp == "XMAS") ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
