#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    ll ans = 0;

    while (getline(cin, str)) {
        regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
        sregex_iterator begin(str.begin(), str.end(), pattern);
        sregex_iterator end;

        for (auto it = begin; it != end; it++) {
            ll x = stoi((*it)[1].str());
            ll y = stoi((*it)[2].str());
            ans += x * y;
        }
    }

    cout << ans << endl;
}
