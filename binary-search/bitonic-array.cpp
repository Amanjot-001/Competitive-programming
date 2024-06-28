#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr(100000);

int check(int mid) {
    if(mid == n-1) return 1;
    if(arr[mid] > arr[mid+1]) return 1;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int q;
        cin >> n >> q;
        arr.resize(n);
        for(int i=0; i<n; i++) cin >> arr[i];

        int lo=0, hi=n-1, peek=0;
        while(lo<=hi) {
            int mid = lo + ((hi-lo) >> 1);
            if(check(mid)) {
                hi=mid-1;
                peek=mid;
            } else {
                lo=mid+1;
            }
        }

        while(q--) {
            int k;
            cin >> k;
            
            vector<int> ans;

            lo=0;
            hi=peek-1;
            while(lo<=hi) {
                int mid = lo + ((hi-lo) >> 1);
                if(arr[mid] == k) {
                    ans.push_back(mid+1);
                    break;
                } else if(arr[mid]>k)
                    hi=mid-1;
                else
                    lo=mid+1;
            }

            lo=peek;
            hi=n-1;
            while(lo<=hi) {
                int mid = lo + ((hi-lo) >> 1);
                if(arr[mid] == k) {
                    ans.push_back(mid+1);
                    break;
                } else if(arr[mid]>k)
                    lo=mid+1;
                else
                    hi=mid-1;
            }

            for(auto &it: ans)
                cout << it << " ";
            cout << '\n';
        }
    }
    return 0;
}