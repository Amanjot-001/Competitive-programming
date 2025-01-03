#include <bits/stdc++.h>
using namespace std;

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        if (b % a == 0)
            cout << (b / a * b) << endl;
        else
            cout << lcm(a, b) << endl;
    }

    return 0;
}
