#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k, x;
		cin >> n >> k >> x;
		if (x != 1)
		{
			cout << "YES" << endl;
			cout << n << endl;
			for (int i = 0; i < n; ++i)
				cout << 1 << " ";
			cout << endl;
		}
		else if (k == 1 || (k == 2 && n & 1 == 1))
			cout << "NO" << endl;
		else
		{
			// 2 or 3 se koi sa bhi number ban jaega, bss odd ke lie starting mai 3 chahiye
			cout << "YES" << endl;
			cout << n / 2 << endl;
			if (n & 1 == 1) {
                cout << 3 << " ";
				n -= 3;
            }
            for (int i = 0; i < n / 2; i++) {
                cout << 2 << " ";
            }
            cout << endl;
		}
	}
	return 0;
}
