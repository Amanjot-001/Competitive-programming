#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int x, y;
		cin >> x >> y;
		int ans = 0;
 
		if(x == 0 && y == 0)
			cout << 0 << endl;
		else {
		
			ans += (y+1)/2;
			x -= ((ans*15) - (y*4));
 
			if(x > 0) {
				ans += (x+14)/15;
			}	
 
			cout << (ans == 0 ? 1 : ans) << endl;
		}
	}
	return 0;
}