#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    ll ans = 0;
	bool flag = true;

    while (getline(cin, str)) {
        regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))");

        sregex_iterator begin(str.begin(), str.end(), pattern);
        sregex_iterator end;

        for (auto it = begin; it != end; it++) {
            string temp = it->str();
			cout << temp << endl;
            if (temp == "do()")
                flag = true;
            else if (temp == "don't()")
                flag = false;
            else {
                if (flag) {
                    ll x = stoll((*it)[1].str());
                    ll y = stoll((*it)[2].str());
                    ans += x * y;
                }
            }
        }
    }

    cout << ans << endl;
	return 0;
}
