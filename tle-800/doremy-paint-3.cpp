#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		map<int, int> mpp;
		for (int &it: arr) {
      		cin >> it;
      		mpp[it]++;
    	}
		
		if(mpp.size() >= 3)
			cout << "no" << endl;
		else {
			if(abs(mpp.begin()->second - mpp.rbegin()->second) <= 1)
				cout << "yes" << endl;
			else 
				cout << "no" << endl;
		}
	}
	return 0;
}