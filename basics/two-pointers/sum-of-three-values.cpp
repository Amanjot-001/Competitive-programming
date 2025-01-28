#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        a[i] = {b, i + 1};
    }

    sort(a.begin(), a.end());
    bool found = false;
    int i, j, k;

    for (k = 0; k < n; k++) {
        i = 0, j = n - 1;
        while (i < j) {
			if(i==k) {
				i++;
				continue;
			}
			if(j==k) {
				j--;
				continue;
			}

            ll sum = a[i].first + a[j].first;

            if (sum == x - a[k].first) {
                found = true;
				break;
			}
            else if (sum < x - a[k].first)
                i++;
            else
                j--;
        }
        if (found) break;
    }

    if (!found)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << a[i].second << " " << a[j].second << " " << a[k].second << endl;

    return 0;
}