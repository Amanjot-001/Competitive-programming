#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		
		vector<char> v(26, 0);

		for(int i=0; i<s.size(); i++)
			v[int(s[i]) - 'a']++;

		string aux;
		for(int i=0; i<26; i++) {
			if(v[i] > 0)
				aux += char(i + 'a');
		}

		int m = aux.size();
		unordered_map<char, char> mpp;
		for(int i=0; i<=m/2; i++) {
			mpp[aux[i]] = aux[m-1-i];
			mpp[aux[m-1-i]] = aux[i];
		}

		string ans;
		for(int i=0; i<s.size(); i++) {
			ans += mpp[s[i]];
		}

		cout << ans << endl;
	}
	return 0;
}
