#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int cnt0 = 0, cnt1 = 0;

		for (auto it : s)
		{
			if (it == '0')
				cnt0++;
			else
				cnt1++;
		}

		if (min(cnt0, cnt1) % 2 == 1)
			cout << "DA" << endl;
		else
			cout << "NET" << endl;
	}
	return 0;
}
