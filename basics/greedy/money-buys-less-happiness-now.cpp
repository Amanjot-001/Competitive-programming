#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while(t--) {
		int m, x;
		cin >> m >> x;
		vector<int> a(m);
		for(int i=0; i<m; i++)	
			cin >> a[i];

		priority_queue<int> maxHeap;
		int budget = 0;
		int happiness = 0;

		for(int i=0; i<m; i++) {
			if(budget >= a[i]) {
				maxHeap.push(a[i]);
				budget -= a[i];
				happiness++;
			} else if(!maxHeap.empty() && maxHeap.top() > a[i]) {
				budget += maxHeap.top() - a[i];
				maxHeap.pop();
				maxHeap.push(a[i]);
			}
			budget += x;
		}

		cout << happiness << endl;
	}

	return 0;
}