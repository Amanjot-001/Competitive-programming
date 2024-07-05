#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	unordered_map<char, int> mpp1, mpp2;
	for(auto &it: s)
		mpp1[it]++;

	int ans=0;
	
	for(int i=0; i<n; i++) {
		char ch = s[i];
		mpp2[ch]++;
		mpp1[ch]--;
		if(mpp1[ch] == 0)
			mpp1.erase(ch);
		
		ans = max(ans, (int)(mpp1.size() + mpp2.size()));
	}

	cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}