#include <bits/stdc++.h>
using namespace std;
#define ll long long

// kadane's

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	ll max_sum = -1e9;
	ll curr = 0;
	for(int i=0; i<n; i++) {
		curr += a[i];
		max_sum = max(max_sum, curr);

		if(curr < 0)
			curr = 0;
	}

	cout << max_sum << endl;
	
    return 0;
}