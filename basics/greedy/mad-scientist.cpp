#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);

	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	int i=0, j=0;
	int ans = 0;
	int curr = 0;

	while(i<n && j<n) {
		if(a[i++] != b[j++])
			curr++;
		else {
			if(curr)
				ans++;
			curr=0;
		}
	}

	cout << ans << endl;

	return 0;
}