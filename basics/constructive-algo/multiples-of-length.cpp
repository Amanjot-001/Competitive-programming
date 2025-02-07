#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

	// full thinking based
	// how to get 0000's in exactly 3 steps

    if (n == 1) {
        for (int z = 0; z < 3; ++z) {
            cout << "1 1\n";
            cout << -A[0] << "\n";
            A[0] = 0;
        }
        return 0;
    }
    cout << "1 " << n << "\n";
    for (int i = 0; i < n - 1; i++) cout << -A[i] * n << " ";
    cout << "0\n";
    cout << "1 " << n - 1 << "\n";
    for (int i = 0; i < n - 1; i++) cout << A[i] * (n - 1) << " ";
    cout << "\n";
    cout << n << " " << n << "\n";
    cout << -A[n - 1] << "\n";
    return 0;

    return 0;
}
