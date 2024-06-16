#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long n, a, b;
		cin >> n >> a >> b;
		long long ans = 0;

		int l = 1, r = min(n, b);
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			int coin = b - mid + 1;
			if (coin >= a)
				l = mid + 1;
			else if (coin < a)
				r = mid - 1;
		}

		long long k = l - 1;
		if (k < 0)
			k = 0;
		ans += k * b - (k * (k - 1)) / 2;
		ans += (n - k) * a;
		cout << ans << endl;
	}
	return 0;
}
