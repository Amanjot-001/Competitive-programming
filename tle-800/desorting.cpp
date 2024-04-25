#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[n], diff = INT_MAX;
		bool isSorted = true;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (i > 0)
			{
				diff = min(diff, arr[i] - arr[i - 1]);
				isSorted = isSorted && (arr[i] >= arr[i - 1]);
			}
		}
		if (!isSorted)
			cout << 0 << endl;
		else
			cout << diff / 2 + 1 << endl;
	}
}
