#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		vector<int> v(n);
		bool has_zero = false;
		for(auto &it: v) {
			cin >> it;
			if(!it)
				has_zero = true;
		}

		if(has_zero) {
			cout << 0 << endl;
			continue;
		}
		
		int ans = 0;

		int negative_cnt = 0;
		for(int i=0; i<n; i++) {
			if(v[i] < 0)
				negative_cnt++;
		}

		if(negative_cnt%2 == 0) {
			cout << 1 << endl;
			cout << 1 << " " << 0 << endl;
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}
