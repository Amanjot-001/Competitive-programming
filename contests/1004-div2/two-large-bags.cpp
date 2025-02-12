#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

		bool possible = true;
        set<int> s1, s2;
        int first = -1;
		int last = -1;
        int x = -1;
        for (int i = 0; i < n; i++) {
            x = a[i];
            if (s1.count(x) && s2.count(x)) {
                if (first != -1) {
                    if (x>first) {
                        possible = false;
                        break;
                    }
                    s1.insert(first);
                    s2.insert(first);
					last = first;
					first = -1;
                } else {
                    first = last+1;
                }
            } else if (s1.count(x)) {
                s2.insert(x);
            } else {
				if(first != -1) {
					if (first == x) {
						s1.insert(x);
						s2.insert(x);
						last = first;
						first = -1;
					} else {
						possible=false;
						break;
					}
				} else {
                    first = x;
                }
            }
        }

		if(possible) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
    }

    return 0;
}