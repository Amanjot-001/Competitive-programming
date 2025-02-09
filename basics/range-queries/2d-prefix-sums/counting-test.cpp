#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
	cin >> t;

	while(t--) {
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;

		vector<vector<int>> p(26, vector<int>(n+1, 0));
		for(int i=0; i<n; i++) {
			for(int j=0; j<26; j++) {
				p[j][i+1] = p[j][i];
			}
			p[s[i] - 'a'][i+1]++;
		}

		while(q--) {
			int l, r;
			char c;
			cin >> l >> r >> c;
			int ch = c-'a';

			int full_cycle_r = r/n;
			int rem_cycle_r = r%n;

			int full_cycle_l = (l-1)/n;
			int rem_cycle_l = (l-1)%n;

			int occ_r = full_cycle_r*p[ch][n] + p[ch][rem_cycle_r];
			int occ_l = full_cycle_l*p[ch][n] + p[ch][rem_cycle_l];

			cout << occ_r - occ_l << endl;
		}
	}

    return 0;
}