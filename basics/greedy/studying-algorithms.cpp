#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];
	
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i=0; i<n && x>0; i++) {
		if(x-a[i] >= 0) {
			ans++;
			x-=a[i];
		} else {
			break;
		}
	}

	cout << ans << endl;

	return 0;
}