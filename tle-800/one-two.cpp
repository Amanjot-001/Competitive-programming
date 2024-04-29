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
		int arr[n];
		for (int &it : arr)
			cin >> it;

		int lcnt =0, rcnt =0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 2)
				rcnt++;
		}	

		int ans = -1;

		for(int i=0; i<n; i++) {
			if(arr[i] == 2) {
				lcnt++;
				rcnt--;
			}
			if(lcnt == rcnt) {
				ans = i+1;
				break;
			}
		}

		cout << ans << endl;
	}

	return 0;
}
