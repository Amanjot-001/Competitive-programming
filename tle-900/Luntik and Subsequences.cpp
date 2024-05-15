#include <bits/stdc++.h>
using namespace std;

int main () {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int cnt0=0, cnt1=0;
		for(int i=0; i<n; i++) {
			int temp;
			cin >> temp;
			if(temp == 0)
				cnt0++;
			else
				cnt1++;
		}

		cout << pow(2, cnt0) * cnt1 << endl;
	}
	return 0;
}