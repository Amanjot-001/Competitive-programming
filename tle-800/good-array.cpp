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
		int arr[n];
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			x %= 2;
			arr[i] = x;
		}
		int diff = 0;
		for (int i = 1; i < n; i++)
		{
			if (arr[i] != arr[i - 1])
				diff++;
		}

		cout << n - diff - 1 << endl;
	}
	return 0;
}
