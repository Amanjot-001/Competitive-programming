#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
		cin >> a[i];

	map<int, int> cnt;
	int nums = 0;
	ll res = 0;

	for(int i=0, j=0; j<n; j++) {
		cnt[a[j]]++;
		if(cnt[a[j]] == 1)
			nums++;
		
		while(nums > k) {
			cnt[a[i]]--;
			if(cnt[a[i]] == 0)
				nums--;
			i++;
		}

		res += (j-i+1);
	}

	cout << res << endl;

    return 0;
}