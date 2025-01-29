#include <bits/stdc++.h>
using namespace std;
#define ll long long

string print(int n) {
	if(!n)
		return "";
	string temp = print(n-1);
	return temp + (char)(n+64) + temp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	cout << print(n);
	
	return 0;
}