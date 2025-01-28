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
	int i, j, k, l;

    for (l = 0; l < n-3; l++) {
        for (k = l+1; k < n-2; k++) {
           i = k+1, j = n - 1;
            while (i < j) {
                ll sum = a[i].first + a[j].first + a[k].first + a[l].first;

                if (sum == x) {
                    cout << a[i].second << " " << a[j].second << " " << a[k].second << " " << a[l].second << endl;
					return 0;
                } else if (sum < x)
                    i++;
                else
                    j--;
            }
        }
    }

	cout << "IMPOSSIBLE" << endl;

    return 0;
}