#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		// first lets match the x coordinate and then whatever is the y coor diff double it as it will take to reach it
		if (d < b || a - b < c - d)
			cout << -1 << endl;
		else
		{
			if (a >= c) // c is behind a then only (x-1, y)
			{
				cout << abs(a - c) + 2 * abs(b - d) << endl;
			}
			else // here it will (x+1, y+1) so need to subtract y axis coor for how much i travelled
			{
				cout << abs(a - c) + 2 * abs(b - (d - abs(a - c))) << endl;
			}
		}
	}
	return 0;
}
