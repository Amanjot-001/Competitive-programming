#include<bits/stdc++.h>
using namespace std;
#define ll long long

int32_t main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	for(int a=1; a<=t; a++) {
		int n;
		cin >> n;

		vector<vector<int>> arr(n, vector<int>(2));
		for(int i=0; i<n; i++) {
			cin >> arr[i][0] >> arr[i][1];
		}

        int max_on_line = 1;

        for(int i=0; i<n; i++) {
            unordered_map<double, int> mpp;

            for(int j=i+1; j<n; j++) {
                double num = arr[j][1] - arr[i][1];
                double den = arr[j][0] - arr[i][0];
                double slope;
                if(den == 0) {
                    slope = INT_MAX;
                } else {
                    slope = num/den;
                }
                mpp[slope]++;

                max_on_line = max(max_on_line, mpp[slope]+1);
            }
        }

		cout << "Case #" << a << ": " << (n-max_on_line) << '\n';
	}

	return 0;
}
