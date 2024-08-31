#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> solve(vector<string> operations, vector<int> x) {
	vector<int> ans;
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    unordered_set<int> maxSet;
    unordered_set<int> minSet;
    
    for(int i = 0; i < operations.size(); ++i) {
        string op = operations[i];
        int val = x[i];
        
        if(op == "PUSH") {
            maxpq.push(val);
            minpq.push(val);
            maxSet.insert(val);
            minSet.insert(val);
        } else if(op == "POP") {
            if(maxSet.find(val) != maxSet.end()) {
                maxSet.erase(val);
            }
            if(minSet.find(val) != minSet.end()) {
                minSet.erase(val);
            }
            
            while(!maxpq.empty() && maxSet.find(maxpq.top()) == maxSet.end()) {
                maxpq.pop();
            }
            
            while(!minpq.empty() && minSet.find(minpq.top()) == minSet.end()) {
                minpq.pop();
            }
        }
        
		cout << maxpq.top()  << " " << minpq.top() << '\n';

		int maxVal = maxpq.top();
		int minVal = minpq.top();
		ans.push_back(maxVal * minVal);
    }
    
    return ans;
}

signed main() {
	vector<string> operations = {"PUSH", "PUSH", "POP", "PUSH", "POP", "PUSH", "POP"};
	vector<int> x = {3, 3, 3, 3, 3, 2, 2};

	vector<int> ans = solve(operations, x);
	for(auto& it : ans)
		cout << it << " ";
	return 0;
}