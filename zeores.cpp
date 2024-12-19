#include <bits/stdc++.h>
using namespace std;

long fact[12], ten[12], nine[12], dp[12];

int DigitCount(long n) {
    int cnt = 0;
    while (n) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int Get_ith_Digit(long n, int i) {
    n = n % ten[i];
    n /= ten[i - 1];
    i = n;
    return i;
}

long calc(int len) {
    long sum = 0;

    for (int i = 1; i <= len; i++) {
        long temp = fact[len] / (fact[i] * fact[len - i]);
        temp *= nine[len - i];
        sum += i * temp;
    }
    return sum;
}

long fun(long n) {
    if (n < 0)
        return 0;

    if (n == 0)
        return 1;

    int cnt = DigitCount(n);
    if (cnt == 1) return 1;

    long ans = dp[cnt - 1];

    long d = n / ten[cnt - 1];
    d--;

    if (d) ans += d * calc(cnt - 1);

    for (int i = cnt - 1; i; i--) {
        d = Get_ith_Digit(n, i);

        if (i == 1)
            ans++;
        else if (d)
            ans += ((d)*calc(i - 1) + ten[i - 1]);
        else
            ans += (n % ten[i] + 1);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;

    dp[1] = ten[0] = fact[0] = nine[0] = 1;

    for (int i = 1; i <= 11; i++) {
        fact[i] = fact[i - 1] * i;
        ten[i] = ten[i - 1] * 10;
        nine[i] = nine[i - 1] * 9;

        if (i > 1) dp[i] = 9 * calc(i - 1) + dp[i - 1];
    }

    for (int t = 1; t <= T; ++t) {
        long a, b;
        cin >> a >> b;

        long ans = fun(b) - fun(a - 1);

        cout << "Case " << t << ": " << ans << endl;
    }

    return 0;
}
