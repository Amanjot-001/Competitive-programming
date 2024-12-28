#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string ans = "";

    while (n && m) {
        if (s[n - 1] == t[m - 1]) {
            ans += s[n - 1];
            n--;
            m--;
        } else if (dp[n - 1][m] > dp[n][m - 1]) {
            n--;
        } else {
            m--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';

    return 0;
}
