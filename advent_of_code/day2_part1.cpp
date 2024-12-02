#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string line;

	int ans = 0;

	for(int i=0; i<N; i++) {
        vector<int> v;
        int num;

		while(true) {
			int x;
			scanf("%d", &x);
			v.push_back(x);

			char c;
			scanf("%c", &c);
			if(c == '\n')
				break;
		}

		int len = (int) v.size();
		bool inc = false, dec = false;
		bool ok = true;

		for(int j=0; j<len-1; j++) {
			int diff = v[j+1] - v[j];
			if(diff > 0) {
				inc = true;
			}

			if(diff < 0) {
				dec = true;
			}

			if(!(1 <= abs(diff) && abs(diff) <= 3)) {
				ok = false;
				break;
			}
		}

		if(ok && !(inc && dec)) {
			ans++;
		}
	}

	cout << ans << endl;
}
