#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;

    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    ll inv_cnt = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else {
            arr[k++] = right[j++];
            inv_cnt += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return inv_cnt;
}

ll mergesort(vector<int>& arr, int l, int r) {
    if (l >= r)
        return 0;
    int m = l + (r - l) / 2;
    ll inv_cnt = 0;

    inv_cnt += mergesort(arr, l, m);
    inv_cnt += mergesort(arr, m + 1, r);
    inv_cnt += merge(arr, l, m, r);

    return inv_cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin.ignore();

        cout << mergesort(arr, 0, n - 1) << endl;
    }

    return 0;
}