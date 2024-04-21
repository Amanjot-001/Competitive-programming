#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int arr[n];
		map<int, int> mpp;
		for(int &it: arr) {
			cin >> it;
			mpp[it]++;
		}
		
		if(mpp[k] > 0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}