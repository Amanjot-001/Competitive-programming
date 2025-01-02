#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll _gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

ll _countDivisors(ll n) {
    ll res = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res++;
            if (n / i != i) {
                res++;
            }
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = a[n - 1];

    for (int i = n - 1; i >= 0; i--) {
        ans = _gcd(a[i], ans);
        if (ans == 1)
            break;
    }

    ans = _countDivisors(ans);

    cout << ans << endl;

    return 0;
}
