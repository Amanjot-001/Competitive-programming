#include <bits/stdc++.h>
using namespace std;
using lli = long long;

void solve() {
	int n;
	cin >> n;
	vector<lli> a(n), b(n), c(n);
	lli tot=0;
	for(int i=0; i<n; i++) {
		cin >> a[i];
		tot+=a[i];
	}
	for(int i=0; i<n; i++)
		cin >> b[i];
	for(int i=0; i<n; i++)
		cin >> c[i];

	tot = (tot+3-1)/3;
	int ans[6] = {-1, -1, -1, -1, -1, -1};
	lli aa=0, bb=0, cc=0;
	int st=0;
	
	for(int i=0; i<n; i++) {
		aa+=a[i];
		bb+=b[i];
		cc+=c[i];

		if(aa >= tot && aa >= bb && aa >= cc && ans[0]==-1) {
			ans[0]=st+1;
			ans[1]=i+1;
			st=i+1;
			aa=0;
			bb=0;
			cc=0;
		} else if(bb >= tot && bb >= aa && bb >= cc && ans[2]==-1) {
			ans[2]=st+1;
			ans[3]=i+1;
			st=i+1;
			aa=0;
			bb=0;
			cc=0;
		} else if(cc >= tot && cc >= bb && cc >= aa && ans[4]==-1) {
			ans[4]=st+1;
			ans[5]=i+1;
			st=i+1;
			aa=0;
			bb=0;
			cc=0;
		}
	}

	if (ans[0] == -1 || ans[2] == -1 || ans[4] == -1)
        cout << -1;
    else {
        for (int i = 0; i < 6; i++) {
            cout << ans[i] << " ";
        }
    }

	cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}