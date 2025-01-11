#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<ll> a;

void generateLuckynum(ll n, ll four, ll seven) {
	if(n>1e10)
		return;

	if(four == seven)
		a.insert(n);
	generateLuckynum(n*10+4, four+1, seven);
	generateLuckynum(n*10+7, four, seven+1);
}

int main() {
	ll n;
	cin >> n;

	generateLuckynum(0, 0, 0);
	auto it = lower_bound(a.begin(), a.end(), n);

	if(it != a.end())
		cout << (*it) << endl;

	return 0;
}
