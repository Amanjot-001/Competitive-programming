#include <bits/stdc++.h>
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

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int &x: a)
		cin >> x;

	vector<int> freq(n+1, 0);
	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i=0; i<=n; i++)
		pq.push(i);

	for(int i=0; i<m; i++)
		freq[a[i]]++;

	while (!pq.empty() && freq[pq.top()] > 0) {
        pq.pop();
    }

    int min_mex = pq.top();

    for(int i=m; i<n; i++) {
    	int out = a[i-m];
    	freq[out]--;
    	
    	if(freq[out] == 0)
    		pq.push(out);

    	int in = a[i];
    	freq[in]++;
    	while (!pq.empty() && freq[pq.top()] > 0) {
            pq.pop();
        }

        min_mex = min(min_mex, pq.top());
    }

    cout << min_mex << endl;

	return 0;
}
