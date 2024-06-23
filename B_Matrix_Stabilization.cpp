#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
        }

        vector<vector<int>> updated_v = v;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int num = v[i][j];
                bool strictlyGreater = true;
                int maxValue = INT_MIN;

                if(i > 0) {
                    if(num <= v[i-1][j]) {
                        strictlyGreater = false;
                    }
                    maxValue = max(maxValue, v[i-1][j]);
                }
                if(i < n-1) {
                    if(num <= v[i+1][j]) {
                        strictlyGreater = false;
                    }
                    maxValue = max(maxValue, v[i+1][j]);
                }
                if(j > 0) {
                    if(num <= v[i][j-1]) {
                        strictlyGreater = false;
                    }
                    maxValue = max(maxValue, v[i][j-1]);
                }
                if(j < m-1) {
                    if(num <= v[i][j+1]) {
                        strictlyGreater = false;
                    }
                    maxValue = max(maxValue, v[i][j+1]);
                }

                if(strictlyGreater) {
                    updated_v[i][j] = maxValue;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << updated_v[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
