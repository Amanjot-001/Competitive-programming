#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int arr [n];
	
		for(int &it: arr)
			cin >> it;

		string ans = "no";
		
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				if(__gcd(arr[i], arr[j]) <= 2) {
					ans = "yes";
					break;
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}
