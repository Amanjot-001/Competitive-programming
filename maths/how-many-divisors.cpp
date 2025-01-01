#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;

    for (int i = 1; i * i <= c; i++) {
        if (c % i == 0) {
            if (i >= a && i <= b)
                ans++;
            if (c / i != i && (c / i) >= a && (c / i) <= b)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
