#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n, d;
	cin >> n >> d;
	vector<lli> arr(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	sort(arr.begin(), arr.end());
	int players_used=0;
	int ans=0;

	int i=n-1;
	while(players_used <= n) {
		lli curr_team = (d+arr[i]-1)/arr[i];
		if(curr_team*arr[i] <= d)
			curr_team++;
		if(players_used + curr_team <= n) {
			ans++;
			players_used += curr_team;
		}
		else
			break;
		i--;
	}

	cout << ans << '\n';
	
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    solve();
    
    return 0;
}