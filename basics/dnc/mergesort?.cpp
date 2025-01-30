#include <bits/stdc++.h>
using namespace std;
#define ll long long

void unsort(vector<int>& arr, int l, int r, int& calls, int target) {
	if(calls>=target || l+1>=r) // acc to ques [l, r)
		return;
	int m = l + (r-l)/2;
	if(calls+2<=target) {
		calls +=  2;
		swap(arr[m-1], arr[m]);
	}
	unsort(arr, l, m, calls, target);
	unsort(arr, m, r, calls, target);
}

vector<int> findPerm(int n, int k) {
	if(k&1==0)
		return {};
	vector<int> arr(n);
	iota(arr.begin(), arr.end(), 1);
	int calls = 1; // initial call
	unsort(arr, 0, n, calls, k);

	if(calls==k)
		return arr;
	return {};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
	cin >> n >> k;
	
	vector<int> ans = findPerm(n, k);

	if(ans.empty()) {
		cout << -1;
	}
	else {
		for(int x: ans)
			cout << x << " ";
	}
		
	cout << endl;

    return 0;
}