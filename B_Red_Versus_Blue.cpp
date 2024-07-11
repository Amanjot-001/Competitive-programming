#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n, r, b;
string ans="";

bool check(int mid) {
	string temp="";
	int lenR=0, lenB=0;
	int consec_R = (r+b-1)/b;

	while(temp.size()<n && lenR<=r && lenB<=b) {
		int x=lenB == b ? mid : min(mid, consec_R);
		bool flag_R = false, flag_B = false;
		
		while(lenR<r && x--) {
			temp+='R';
			lenR++;
			flag_R=true;
		}
		x= lenR==r ? mid : 1;
		while(lenB<b && x--) {
			temp+='B';
			lenB++;
			flag_B=true;
		}

		if(!flag_R || !flag_B)
			break;
	}

	if(temp.size() == n && lenR==r && lenB==b) {
		// cout << temp << endl;
		ans = temp;
        return true;
	}
	return false;
}

void solve() {
	cin >> n >> r >> b;

	int lo=1, hi=n;
	string tempAns;

	while(lo<=hi) {
		int mid = lo + ((hi-lo) >> 1);
		if(check(mid)) {
			hi=mid-1;
		} else {
			lo=mid+1;
		}
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