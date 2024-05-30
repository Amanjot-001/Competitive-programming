#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		string ans = "YES";
		for(int i=0; i<n-1; i++) {
			char ch = int(s[i]);
			if(ch > int(s[i+1])) {
				ans = "NO";
				break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
