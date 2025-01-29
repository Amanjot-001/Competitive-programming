#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Stack {
	vector<ll> s, smin = {LLONG_MAX}, smax = {LLONG_MIN};

	void push(ll x) {
		s.push_back(x);
		smin.push_back(::min(smin.back(), x));
		smax.push_back(::max(smax.back(), x));
	}

	ll pop() {
		ll res = s.back();
		s.pop_back();
		smax.pop_back();
		smin.pop_back();
		return res;
	}

	bool empty() {
		return s.empty();
	}

	ll min() {
		return smin.back();
	}

	ll max() {
		return smax.back();
	}
};

Stack s1, s2;

void add(ll x) {
	s2.push(x);
}

void remove() {
	if(s1.empty()) {
		while(!s2.empty()) {
			s1.push(s2.pop());
		}
	}

	s1.pop();
}

ll k;

bool good() {
	ll mn = min(s1.min(), s2.min());
	ll mx = max(s1.max(), s2.max());
	return mx-mn<=k;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i=0; i<n; i++)
		cin >> a[i];

	ll res = 0;
	for(int j=0, i=0; j<n; j++) {
		add(a[j]);
		while(!good()) {
			remove();
			i++;
		}

		res += (j-i+1);
	}

	cout << res << endl;

	return 0;
}