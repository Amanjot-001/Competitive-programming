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
		if ((a[0] + a[1] + a[2]) % 2 != 0)
			ans = -1;
		else if((a[0]+a[1])<= a[2])
			ans = a[0]+a[1];
		else 
			ans = (a[0]+a[1]+a[2])/2;

		cout << ans << endl;
	}
	return 0;
}
