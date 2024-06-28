#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100000];

int check(int mid) {
    if(arr[mid] < arr[0]) return 1;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];

        int lo = 0, hi = n-1, ans = 0;

        while(lo<=hi) {
            int mid = lo + ((hi-lo) >> 1);
            if(check(mid)) {
                hi=mid-1;
                ans=mid;
            }
            else
                lo=mid+1;
        }

        cout << ans << '\n';
    }
    return 0;
}