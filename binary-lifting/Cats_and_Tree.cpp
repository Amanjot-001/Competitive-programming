#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> parent, jump;
vector<bool> occupied;
vector<vector<int>> table;
int MAXBIT=18;

void setBit() {
	MAXBIT=0;
	while((1<<MAXBIT) <= n)
		MAXBIT++;
	MAXBIT--;
}

void build() {
	table.resize(MAXBIT+1, vector<int>(n+1));
	table[0] = parent;
	for(int i=1; i<=MAXBIT; i++) {
		for(int j=1; j<=n; j++) {
			int p = table[i-1][j];
			if(p!=0)
				table[i][j] = table[i-1][p];
		}
	}
}

int cal(int c) {
	int curr=jump[c];
	if(occupied[curr])
		return 0;
	
	int j=1;
	for(int i=MAXBIT; i>=0; i--) {
		int jp = table[i][curr];
		if(jp!=0 && !occupied[jp]) {
			curr = jp;
			j += (1<<i);
		}
	}

	occupied[curr]=true;
	return j;
}

signed main() {
	cin >> n;
	parent.resize(n+1, 0);
	jump.resize(n+1, 0);
	occupied.resize(n+1, false);

	for(int i=1; i<=n; i++) {
		cin >> parent[i];
	}

	for(int i=1; i<=n; i++) {
		cin >> jump[i];
	}

	setBit();
	build();

	for(int i=1; i<=n; i++) {
		int jumps = cal(i);
		cout << jumps << '\n';
	}

	return 0;
}