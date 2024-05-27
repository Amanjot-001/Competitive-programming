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

		string ans;

		int arr[4] = {0, 0, 0, 0};
		
		for(char s: str) {
			if(s == 'E')
				arr[0]++;
			else if(s == 'W')
				arr[2]++;
			if(s == 'N')
				arr[1]++;
			else if(s == 'S')
				arr[3]++;
		}
			
		for(int i=0; i<4; i++) {
			if(arr[i] > 0){
				if(arr[i] % 2 != arr [(i+2)%4] % 2)
					ans = "NO";
			}
		}

		if(ans != "NO") {
			ans = "";
			for(int i=0; i<str.size(); i++) {
				switch(str[i]) {
					case 'E':
						if(arr[0] != 1) {
							ans += 'R';
							arr[0]--;
						}
						else {
							ans += 'H';
							arr[0]--;
						}
						break;
					case 'W':
						ans += 'R';
						break;
					case 'N':
						if(arr[1] != 1) {
							ans += 'R';
							arr[1]--;
						}
						else {
							ans += 'H';
							arr[1]--;
						}
						break;
					case 'S':
						ans += 'R';
						break;
				}
			}
		}

		cout << ans << endl;

	}
	return 0;
}
