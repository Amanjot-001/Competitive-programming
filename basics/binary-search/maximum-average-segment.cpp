#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, d;
vector<int> a;
int leftIdx, rightIdx;

void findSegment(vector<double>& prefix) {
	double minPrefix=0;
	int minIdx = 0;

	for(int i=d; i<=n; i++) {
		if(prefix[i] - minPrefix >= 0) {
			leftIdx = minIdx;
			rightIdx = i-1;
			return;
		}

		if(prefix[i-d+1] < minPrefix) {
			minPrefix = prefix[i-d+1];
			minIdx = i-d+1;
		}
	}

	return;
}

bool check(double x) {
	vector<double> prefix(n+1, 0);
	for(int i=1; i<=n; i++) {
		prefix[i] = prefix[i-1] + (a[i-1]-x);
	}

	double minprefix = 0;
	for(int i=d; i<=n; i++) {
		if(prefix[i] - minprefix >= 0) {
			findSegment(prefix);
			return true;
		}

		minprefix = min(minprefix, prefix[i-d+1]);
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> d;
	a.resize(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	double l=0, r=100;
	while(abs(r-l) > 1e-7) {
		double m = (l+r)/2.0;
		if(check(m)) {
			l=m;
		} else {
			r=m;
		}
	}

	cout << leftIdx+1 << " " << rightIdx+1 << endl;

	return 0;
}