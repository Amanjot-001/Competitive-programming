#include <bits/stdc++.h>
using namespace std;
#define ll long long

// editorial ni smj aya ache se
// so instead maintained a separate prefix sums for both categories
// and calculated accordingly

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
		int n, m;
		cin >> n >> m;
		vector<ll> a(n);
		for(int i=0; i<n; i++)
			cin >> a[i];
		
		vector<ll> p(n+1, 0);
		for(int i=1; i<=n; i++)
			p[i] = p[i-1] + a[i-1];
		
		int ops = 0;
		ll s = 0;

		priority_queue<ll> maxHeap;
		for(int i=m; i>1; i--) {
			maxHeap.push(a[i-1]);
			s += a[i-1];
			while(!maxHeap.empty() && s > 0) {
				ll maxEle = maxHeap.top();
				maxHeap.pop();
				s -= 2*maxEle;
				ops++;
			}
		}

		s = 0;
		priority_queue<ll, vector<ll>, greater<ll>> minHeap;
		for(int i=m+1; i<=n; i++) {
			minHeap.push(a[i-1]);
			s += a[i-1];
			while(!minHeap.empty() && s < 0) {
				ll minEle = minHeap.top();
				minHeap.pop();
				s += 2*abs(minEle);
				ops++;
			}
		}

		cout << ops << endl;
	}

	return 0;
}