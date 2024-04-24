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

		sort(arr, arr + n);

		if(arr[0] == arr[n-1])
			cout << -1 << endl;
		else {
			int x=0;
			while(arr[0] == arr[x]) x++;
			cout << x << " " << n-x << endl;
		
			for(int i=0; i<x; i++)
				cout << arr[i] << " ";
			cout << endl;
			for(int i=x; i<n; i++)
				cout << arr[i] << " ";
			cout << endl;
		}
		
	}
	return 0;
}