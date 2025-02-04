#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n, m;
	cin >> n >> m;

	int len = 300;
	cout << string(len, '5') << endl;
	cout << (string(len-1, '4') + '5') << endl;

	return 0;
}