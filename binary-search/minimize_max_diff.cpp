#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n, k;
vector<int> arr;

int check(int mid) {
    int needed=0;
    for(int i=1; i<n; i++) {
        needed += (((arr[i] - arr[i-1])+ mid-1)/mid) - 1;
    }

    return needed <= k;
}

void solve() {
    cin >> n >> k;
    arr.resize(n);
    int lo=1, hi=0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(i) hi=max(hi, arr[i]-arr[i-1]);
    }

    int ans=-1;

    while(lo<=hi) {
        int mid = lo + ((hi-lo) >> 1);
        if(check(mid)) {
            ans=mid;
            hi=mid-1;
        } else {
            lo=mid+1;
        }
    }

    cout << ans << '\n';

}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;

    while(t--)
        solve();
    
    return 0;
}