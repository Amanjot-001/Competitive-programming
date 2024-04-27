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
		int num1 = 0, num2 = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (x == 1)
				num2++;
			else
				num1++;
		}

		if(num1<=num2) {
			if(num1%2 != 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		} else {
			int ans = num1 - n/2;
			if(n/2 % 2 != 0)
				ans++;
			cout << ans << endl;
		}
	}
	return 0;
}
