#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005];
bool ex[100005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    memset(b, -1, sizeof(b));

    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1])  // If MEX changes at i
        {
            b[i] = a[i - 1];  // Place the previous MEX value in `b`
            ex[b[i]] = 1;     // Mark it as used
        }
    }
    ex[a[n]] = 1;  // Mark last MEX value as used

    int m = 0;  // Smallest unused number
    for (int i = 1; i <= n; i++) {
        while (ex[m])  // Find the next unused number
            m++;

        if (b[i] == -1)  // If `b[i]` is not filled yet
        {
            b[i] = m;   // Fill it with the smallest unused number
            ex[m] = 1;  // Mark it as used
        }
        printf("%d ", b[i]);  // Print the result
    }

	return 0;
}
