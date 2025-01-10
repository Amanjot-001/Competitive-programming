#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const int MOD = 1e9+7;
 
int32_t main() {
	int n;
	cin >> n;
	int ans=1;
 
	// 2^n but using iteration as 2^n can be very large so cant use stl directly
	for(int i=0; i<n; i++)
		ans = ans*2%MOD;
	
	cout << ans << '\n';
	return 0;
}
