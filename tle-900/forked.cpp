#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	int dx[4] = {1, 1, -1, -1};
	int dy[4] = {1, -1, 1, -1};

	while (t--)
	{
		int a, b, xk, yk, xq, yq;
		cin >> a >> b >> xk >> yk >> xq >> yq;

		set<pair<int, int>> vk, vq;
		for (int i = 0; i < 4; i++)
		{
			vk.insert({xk + dx[i] * a, yk + dy[i] * b});
			vk.insert({xk + dx[i] * b, yk + dy[i] * a});

			vq.insert({xq + dx[i] * a, yq + dy[i] * b});
			vq.insert({xq + dx[i] * b, yq + dy[i] * a});
		}

		int ans = 0;
		for (auto it : vk)
		{
			if (vq.find(it) != vq.end())
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
