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
		string str;
		cin >> str;
		int ans = n;
		int l=0, r=n-1;
		
		while(l<r && str[l] != str[r]) {
			l++;
			r--;
			ans -= 2;
		}

		cout << ans << endl;
	}
	return 0;
}
