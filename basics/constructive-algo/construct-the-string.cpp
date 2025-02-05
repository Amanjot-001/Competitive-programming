#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
		cin >> n >> a >> b;

		string s = "";
		while(s.size() < n) {
			int i;
			for(i=0; i<b && s.size() < n; i++) {
				s += (char)(i+'a');
			}
		}

		cout << s << endl;
    }

    return 0;
}