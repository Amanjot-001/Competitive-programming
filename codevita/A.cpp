#include <bits/stdc++.h>
using namespace std;

int calculateRemovedWorth(const string &str, const vector<int> &worth)
{
	int n = str.size();
	vector<vector<int>> dp(n, vector<int>(2, 0));

	dp[0][str[0] - '0'] = worth[0];

	for (int i = 1; i < n; ++i)
	{
		int curr = str[i] - '0';
		int prev = 1 - curr;

		dp[i][curr] = max(dp[i - 1][prev] + worth[i], dp[i - 1][curr]);
		dp[i][prev] = dp[i - 1][prev];
	}

	int maxWorth = max(dp[n - 1][0], dp[n - 1][1]);

	int totalWorth = accumulate(worth.begin(), worth.end(), 0);

	return totalWorth - maxWorth;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;

	int n = s.size();
	vector<int> worth(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> worth[i];
	}

	cout << calculateRemovedWorth(s, worth);
	return 0;
}
