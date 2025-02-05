#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;

	if(n==1) {
		cout << "1" << endl;
	}
	else if(n<4) {
		cout << "NO SOLUTION" << endl;
	} else {
		if(n&1) {
			for(int i=n; i>0; i-=2)
				cout << i << " ";
			for(int i=n-1; i>0; i-=2)
				cout << i << " ";
		} else {
			for(int i=n-1; i>0; i-=2)
				cout << i << " ";
			for(int i=n; i>0; i-=2)
				cout << i << " ";
		}
		
		cout << endl;
	}

    return 0;
}