#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;

		string s;
		cin >> s;

		vector<int> v(m);
		for(int i=0; i<m; i++)
			cin >> v[i];
		
		string c;
		cin >> c;

		sort(c.begin(), c.end());
		sort(v.begin(), v.end());

		int unique_idx = 0;
        for(int i = 1; i < m; i++) {
            if(v[i] != v[unique_idx]) {
                unique_idx++;
                v[unique_idx] = v[i];
            }
        }
        unique_idx++;

        int duplicates_count = m - unique_idx;
        if(duplicates_count > 0) {
            c.erase(c.end() - duplicates_count, c.end());
        }

		for(int i=0; i<unique_idx; i++) {
			s[v[i]-1] = c[i];
		}

		cout << s << endl;
	}
	return 0;
}
