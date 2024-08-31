#include <bits/stdc++.h>
using namespace std;
#define ll long long 

signed main() {
	vector<int> task = {1, 2, 2, 1, 3, 1, 3};
	int m=2;

	unordered_map<int, int> freq;
	for(int i=0; i<task.size(); i++) {
		freq[task[i]]++;
	}

	int ans=0;
	int temp=0;
	for(auto& it : freq) {
		if(it.second >= m)
			ans += m;
		else 
			temp += it.second;
	}

	ans += temp/m;
	cout << ans << '\n';
}