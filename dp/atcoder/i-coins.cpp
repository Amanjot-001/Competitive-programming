#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
    dp[0][0] = 1.0;  // 0 coins, 0 heads

    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] * (1 - p[i - 1]);  // No heads
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] * p[i - 1] + dp[i - 1][j] * (1 - p[i - 1]);
        }
    }

    double result = 0.0;
    for (int j = (n / 2) + 1; j <= n; j++) {
        result += dp[n][j];
    }

    cout << fixed << setprecision(9) << result << '\n';
    return 0;
}
