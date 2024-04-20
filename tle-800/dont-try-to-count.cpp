#include <bits/stdc++.h>
using namespace std;

bool isSubstring(string s1, string s2) {
	if (s2.find(s1) != string::npos) // not found
		return true;
	return false;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		string x, s;
		cin >> x >> s;

		int ans=0;
		for(int i=0; i<6; i++) {
			if(isSubstring(s, x))
				break;
			x+=x;
			ans++;
		}
		if(ans>=6)
			cout << -1 << endl;
		else 
			cout << ans << endl;
	}
}
