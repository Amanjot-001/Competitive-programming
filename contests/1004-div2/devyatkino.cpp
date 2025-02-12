#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll n) {
    while (n > 0) {
        if (n % 10 == 7) return true;
        n /= 10;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ans = 10, cnt;
        for (ll i = 9; i < 100000000000; i = i * 10 + 9) {
            cnt = 0;
            ll m = n;
            while (!check(m)) {
                cnt++;
                m += i;
            }

            ans = min(ans, cnt);
        }

        cout << ans << endl;
    }

    return 0;
}