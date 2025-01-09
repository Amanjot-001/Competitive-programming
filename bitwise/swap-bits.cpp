#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		int n;
		cin >> n;

		unsigned int evenmask = 0xAAAAAAAA; // 10101010....
		unsigned int oddmask = 0x55555555;  // 01010101....

		unsigned int even = n & evenmask;
		unsigned int odd = n & oddmask;

		even >>= 1;
		odd <<= 1;

		cout << (even | odd) << endl;
	}

	return 0;
}