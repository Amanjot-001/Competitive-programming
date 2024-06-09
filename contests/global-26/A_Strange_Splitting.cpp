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
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		if (v[0] != v[n - 1])
		{
			cout << "YES" << endl;
			if (v[1] != v[n - 1])
			{
				cout << 'B';
				for (int i = 1; i < n; i++)
				{
					cout << 'R';
				}
			}
			else {
				for (int i = 0; i < n-1; i++)
				{
					cout << 'R';
				}
				cout << 'B';
			}
			cout << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}