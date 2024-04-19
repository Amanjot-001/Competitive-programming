#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		
		int ans=0, prev=0;
		for(int i=0; i<n; i++) {
			if(str[i] == '.'){
				prev++;
				ans++;
			}
			else
				prev=0;
			if(prev == 3){
				ans=2;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
