#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;
	vector<pair<int, int>> a(n);
	for(int i=0; i<n; i++) {
		int b;
		cin >> b;
		a[i] = {b, i+1};
	}

	sort(a.begin(), a.end());
	
	int i=0, j=n-1;
	while(i<n && j>i) {
		ll sum = a[i].first + a[j].first;
		if(sum == x)
			break;
		else if(sum > x)
			j--;
		else
			i++;
	}

	if(i==j)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << a[i].second << " " << a[j].second << endl;

	return 0;
}