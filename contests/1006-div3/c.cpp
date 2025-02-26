#include <bits/stdc++.h>
#include <bit>
using namespace std;
#define ll long long

const int MOD = 1e9+7;

int msb_position(int num) {
    if (num == 0) return -1;
    return 31 - __builtin_clz(num);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif

	int t;
	cin >> t;	

	while(t--) {
		int n, x;
		cin >> n >> x;

		vector<int> ans;
    	int mex = 0;

	    for (int bit = 0; bit < 30 && ans.size() < n-1; ++bit) {
	        if (x & (1 << bit)) { 
	            for (int i = mex; i < (1 << (bit+1)) && ans.size() < n-1; ++i) {
	                ans.push_back(i);
	            }
	            mex = (1 << (bit+1));
	        } else {
	        	break;
	        }
	    }

	    int candidate;
        if (!ans.empty()) {
            candidate = ans.back() + 1;
        } else {
            candidate = 1;
        }

        if (msb_position(candidate) == msb_position(x)) {
            ans.push_back(candidate);
        } else {
            ans.push_back(x);
        }

	    while (ans.size() < n) ans.push_back(0);

	    for (int num : ans)
	        cout << num << " ";
	    cout << "\n";
	}

	return 0;
}
