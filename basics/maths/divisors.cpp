#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> smaller, larger;
	for(int i=1; i*i<=n; i++) {
		if(n%i == 0) {
			smaller.push_back(i);
			if(n/i != i) {
				larger.push_back(n/i);
			}
		}
	}

	for(int i=0; i<smaller.size(); i++) {
		cout << smaller[i] << endl;
	}

	for(int i=larger.size()-1; i>=0; i--) {
		cout << larger[i] << endl;
	}
}
