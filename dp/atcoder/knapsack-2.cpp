#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll total = 1e5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, w;
    cin >> n >> w;
    vector<ll> weight(n), value(n);
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];

    vector<ll> dp(total + 1, 1e18);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (ll j = total; j >= value[i]; j--) {
            dp[j] = min(dp[j], dp[j - value[i]] + weight[i]);
        }
    }

    int ans = 0;
    for (int v = total; v >= 0; v--) {
        if (dp[v] <= w) {
            ans = v;
			break;
        }
    }

    cout << ans << '\n';

    return 0;
}
