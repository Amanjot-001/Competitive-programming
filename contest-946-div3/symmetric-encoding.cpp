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

		unordered_map<char, int>mpp;
		string aux;
		string ans;

		for(int i=0; i<s.size(); i++) {
			if(mpp.find(s[i]) == mpp.end())
				aux+= s[i];
			mpp[s[i]]++;
		}

		sort(aux.begin(), aux.end());

		for(int i=0; i<s.size(); i++) {
			int idx = aux.find(s[i]);
			ans += aux[aux.size()-1-idx];
		}

		cout << ans << endl;
	}
	return 0;
}
