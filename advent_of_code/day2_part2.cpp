#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000;

bool helper(vector<int> &arr) {
    bool inc = false, dec = false;
    bool ok = true;
    int len = (int)arr.size();

    for (int j = 0; j < len - 1; j++) {
        int diff = arr[j + 1] - arr[j];
        if (diff > 0) {
            inc = true;
        }

        if (diff < 0) {
            dec = true;
        }

        if (!(1 <= abs(diff) && abs(diff) <= 3)) {
            ok = false;
            break;
        }
    }

    return ok && !(inc && dec);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;

    int ans = 0;

    for (int i = 0; i < N; i++) {
        vector<int> v;
        int num;

        while (true) {
            int x;
            scanf("%d", &x);
            v.push_back(x);

            char c;
            scanf("%c", &c);
            if (c == '\n')
                break;
        }

        int len = (int)v.size();

        for (int j = 0; j < len; j++) {
            vector<int> temp;
            for (int k = 0; k < len; k++) {
                if (j == k)
                    continue;
                temp.push_back(v[k]);
            }
            if (helper(temp)) {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
}
