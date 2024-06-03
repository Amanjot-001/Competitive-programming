#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, f, k;
		cin >> n >> f >> k;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

		int val = arr[f-1];

		sort(arr.begin(), arr.end(), greater<int>());

		if(arr[k-1] < val)
			cout << "YES" << endl;
		else if(arr[k-1] > val)
			cout << "NO" << endl;
		else {
			if(n >= k+1 && arr[k] == val)
				cout << "maybe" << endl;
			else
				cout << "yes" << endl;
		}
	}
	return 0;
}
