#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        bool ans = false;

        for (int i = 0; i < n - 1; i++) {
            int first = v[i];
            int second = v[i + 1];

            if (first < second) {
                swap(first, second);
            }

            if (2 * second > first) {
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}
