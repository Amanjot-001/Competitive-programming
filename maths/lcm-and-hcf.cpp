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

ll _lcm(ll a, ll b) {
    return a / _gcd(a, b) * b;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        ll hcf = _gcd(a, b);
        ll lcm = _lcm(a, b);

        cout << lcm << " " << hcf << endl;
    }

    return 0;
}