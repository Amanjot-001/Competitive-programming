#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<string> v;
    string str;

    while (getline(cin, str))
        v.push_back(str);

    int n = v.size();
    int m = v[0].size();

    vector<vector<int>> dir1 = {{-1, -1}, {-1, 1}};
    vector<vector<int>> dir2 = {{1, 1}, {1, -1}};

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c = v[i][j];

            if (c == 'A') {
                bool ok = false;

                for (int k = 0; k < 2; k++) {
                    int rd = i + dir1[k][0];
                    int cd = j + dir1[k][1];

                    int opp_rd = i + dir2[k][0];
                    int opp_cd = j + dir2[k][1];

                    if (rd < 0 || cd < 0 || rd >= n || cd >= m) {
                        ok = false;
                        break;
                    }

                    if (opp_rd < 0 || opp_cd < 0 || opp_rd >= n || opp_cd >= m) {
                        ok = false;
                        break;
                    }

                    char c1 = v[rd][cd];
                    char c2 = v[opp_rd][opp_cd];

                    if (c1 != c2 && (c1 == 'M' || c1 == 'S') && (c2 == 'M' || c2 == 'S')) {
                        ok = true;
                    } else {
                        ok = false;
                        break;
                    }
                }

                if (ok) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
