#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;

        bool found[k];
        memset(found, false, sizeof(found));

        string res = "";
        int cnt = 0;
        for (char c : s) {
            if (res.size() == n)
            	break;

            cnt += (!found[c - 'a']);
            found[c - 'a'] = true;

            if (cnt == k) {
                memset(found, false, sizeof(found));
                cnt = 0;
                res += c;
            }
        }

        if (res.size() == n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
            for (int i = 0; i < k; i++) {
                if (!found[i]) {
                    while (res.size() < n) {
                        res += (char)('a' + i);
                    }
                }
            }

            cout << res << endl;
        }
    }

	return 0;
}