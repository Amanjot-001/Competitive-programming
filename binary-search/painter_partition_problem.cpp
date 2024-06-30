#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
vector<int> arr;

int check(int mid) {
    int last_painter_time_left=0;
    int new_painter_spawned=0;

    for(int i=0; i<n; i++) {
        if(last_painter_time_left >= arr[i]) {
            last_painter_time_left -= arr[i];
        } else {
            new_painter_spawned++;
            if(new_painter_spawned > k)
                return 0;
            last_painter_time_left = mid;
            if(last_painter_time_left >= arr[i])
                last_painter_time_left -= arr[i];
            else
                return 0;
        }
    }
    return 1;
}

int32_t main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        arr.resize(n);
        int sum=0;
        int lo=0, hi=0, ans=-1;

        for(int i=0; i<n; i++) {
            cin >> arr[i];
            sum += arr[i];
            lo = max(lo, arr[i]);
        }
        hi=sum;

        while(lo<=hi) {
            int mid = lo + ((hi-lo) >> 1);
            if(check(mid)) {
                hi=mid-1;
                ans=mid;
            } else {
                lo=mid+1;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}