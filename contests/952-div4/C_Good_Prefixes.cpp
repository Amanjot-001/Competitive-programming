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
		vector<int> arr(n);
		for(int i=0; i<n; i++)
			cin >> arr[i];

		long long sum = 0;
		int ele = 0;
		int ans = 0;
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			int x = arr[i];
			if (x == 0 && flag)
				ans++;
			else
			{
				if (ele <= x)
				{
					sum += ele;
					ele = x;
				}
				else
				{
					sum += x;
				}
				if (sum == ele) {
					flag = true;
					ans++;
				} else {
					flag = false;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
