#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		for(int &it: arr)
        	cin >> it;
		
		if(arr[0] == 1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
