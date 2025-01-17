#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double

int n, x, y;

bool check(int m) {
    int remTime = m - min(x, y);
	if(remTime < 0)
		return false;
    int cnt = (remTime / x) + (remTime / y);
    return cnt >= (n - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y;

    int l = 0, r = max(x, y) * n;
    while (l + 1 < r) {
        int m = l + ((r - l) >> 1);

        if (check(m))
            r = m;
        else
            l = m;
    }

    cout << r << endl;

    return 0;
}