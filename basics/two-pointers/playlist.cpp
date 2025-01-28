#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	map<int, int> cnt;
	int num = 0;
	int ans = 0;

	for(int i=0, j=0; j<n; j++) {
		cnt[a[j]]++;
		if(cnt[a[j]] == 1)
			num++;
		else {
			ans = max(ans, num);
			while(cnt[a[j]] != 1) {
				cnt[a[i]]--;
				i++;
			}
			num = j-i+1;
		}
	}

	ans = max(ans, num);

	cout << ans << endl;

	return 0;
}