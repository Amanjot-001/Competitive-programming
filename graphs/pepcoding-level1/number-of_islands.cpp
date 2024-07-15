#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void drawTree(vector<vector<int>> &arr, int i, int j, vector<vector<bool>> &vis) {
	if(i<0 || j<0 || i>=arr.size() || j>= arr[i].size() || arr[i][j] == 1 || vis[i][j])
		return;
	
	vis[i][j] = true;
	
	drawTree(arr, i, j-1, vis);
	drawTree(arr, i, j+1, vis);
	drawTree(arr, i-1, j, vis);
	drawTree(arr, i+1, j, vis);

	return;
}

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> arr(n, vector<int> (m));

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<bool>> vis(n, vector<bool>(m, false));
	int cnt=0;

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j] == 0 && !vis[i][j]) {
				drawTree(arr, i, j, vis);
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}
