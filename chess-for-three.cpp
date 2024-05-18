#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a[3];
		for (int &it : a)
			cin >> it;
		int ans = 0;
		if ((a[0] + a[1] + a[2]) % 2 == 0)
		{
			while (a[1] && a[2])
			{
				a[1]--;
				a[2]--;
				sort(a, a + 3);
				ans++;
			}
		}
		else
			ans = -1;

		cout << ans << endl;
	}
	return 0;
}
