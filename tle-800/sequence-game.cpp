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
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;

			if (i && v.back() > x)
				v.push_back(1);
			v.push_back(x);
		}

		cout << v.size() << endl;
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
	}

	return 0;
}