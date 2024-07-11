#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;

	for(int i=0; i<5; i++) {
		if (a <= b && a <= c) {
            a++;
        } else if (b <= a && b <= c) {
            b++;
        } else {
            c++;
        }
	}

	cout << (a * b * c )<< '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}