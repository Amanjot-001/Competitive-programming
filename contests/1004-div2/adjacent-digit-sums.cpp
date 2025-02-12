#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(int x, int y) {
    if (y == x + 1)
        return true;

    int diff = x + 1 - y;
    if (diff > 0 && diff % 9 == 0) {
        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        if (check(x, y)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}