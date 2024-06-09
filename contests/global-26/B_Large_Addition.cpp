#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long x;
		cin >> x;
		string ans = "YES";

		while(x>0) {
			int d = x%10;
			if(d == 9 || d<0 || x<10) {
				ans = "NO";
				break;
			} else {
				x /= 10;
				if(x<0) {
					ans = "NO";
					break;
				}	
				x--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
