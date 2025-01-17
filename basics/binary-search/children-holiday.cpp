#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double

ll m, n;
vector<ll> t, z, y, ans;

bool check(ll time) {
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        ll cycle = z[i] * t[i] + y[i];
        ll total_cycles = time / cycle;
        ll balloons = total_cycles * z[i];
        ll rem_time = time % cycle;

        if (rem_time >= t[i])
            balloons += min(z[i], rem_time / t[i]);

        ans[i] = balloons;
        res += balloons;
    }

    return res >= m;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    t.resize(n), z.resize(n), y.resize(n), ans.resize(n);

    for (int i = 0; i < n; i++)
        cin >> t[i] >> z[i] >> y[i];

	if(m==0) {
		cout << 0 << endl;
		for(int i=0; i<n; i++)
			cout << 0 << " ";
		return 0;
	}

    ll l = 0, r = 1e9;

    while (l + 1 < r) {
        ll mid = l + ((r - l) >> 1);

        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << endl;
	ll time = r;
	
	for (ll i = 0; i < n; i++) {
        ll cycle = z[i] * t[i] + y[i];
        ll total_cycles = time / cycle;
        ll balloons = total_cycles * z[i];
        ll rem_time = time % cycle;

        if (rem_time >= t[i])
            balloons += min(z[i], rem_time / t[i]);

        ans[i] = balloons;
    }

    ll blown = 0;
    for (ll i = 0; i < n; i++) {
        if (blown + ans[i] > m) {
            if (m > 0) {
                cout << m - blown << " ";
                m = 0;  // just to print 0 for all next i's
            } else {
                cout << 0 << " ";
            }
        } else {
            cout << ans[i] << " ";
        }
        blown += ans[i];
    }
    cout << endl;

    return 0;
}