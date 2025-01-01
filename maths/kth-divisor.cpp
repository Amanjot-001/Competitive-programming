#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> smaller, larger;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            smaller.push_back(i);
            if (n / i != i) {
                larger.push_back(n / i);
            }
        }
    }

    ll ans = -1;

    for (ll i = 0; i < smaller.size() && k >= 0; i++) {
        k--;
        if (k == 0) {
            ans = smaller[i];
        }
    }

    for (ll i = larger.size() - 1; i >= 0 && k >= 0; i--) {
        k--;
        if (k == 0) {
            ans = larger[i];
        }
    }

    cout << ans << endl;

    return 0;
}
