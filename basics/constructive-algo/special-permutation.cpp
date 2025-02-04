#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n & 1) {
			 for (int i = n; i > n / 2 + 1; i--)
                cout << i << " ";
            for (int i = 1; i <= n / 2 + 1; i++)
                cout << i << " ";
        } else {
           for (int i = n; i > 0; i--)
                cout << i << " ";
        }

        cout << endl;
    }

    return 0;
}