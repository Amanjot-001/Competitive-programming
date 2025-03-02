#include <bits/stdc++.h>
#include <bit>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
		freopen("outputf.txt", "w", stdout);
	#endif

	int n;
	cin >> n;
	vector<int> a(n);
	int s = 0;

	for(int& x: a) {
		cin >> x;
		s ^= x;
	}

	for(int i=0; i<n; i++)
		cout << (s^a[i]) << " ";

	cout << endl;

	return 0;
}
