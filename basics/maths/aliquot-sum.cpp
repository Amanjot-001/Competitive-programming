#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;
int d[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for(int i=1; i<N; i++) {
		for(int j=i; j<N; j+=i) {
			if(j != i)
				d[j]+=i;
		}
	}

	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;

		if(d[n] > n)
			cout << "abundant" << endl;
		else if(d[n] < n)
			cout << "deficient" << endl;
		else 
			cout << "perfect" << endl;
	}
	
	return 0;
}
