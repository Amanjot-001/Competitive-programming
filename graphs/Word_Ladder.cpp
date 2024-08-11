// https://leetcode.com/problems/word-ladder/description/?envType=study-plan-v2&envId=top-interview-150
// same as min genetic mutation but refactored code in this
// no need to make extra graph use wordList only
class Solution {
public:
    unordered_map<string, vector<string>> graph;

    bool isNode(string x, string y) {
        int diff=0;
        for(int i=0; i<x.size(); i++) {
            if(x[i] != y[i]) {
                diff++;
                if(diff>1)
                    return false;
            }
        }
        return diff==1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();

        unordered_set<string> vis;
        queue<string> q;
        q.push(beginWord);
        int level=0;

        while(!q.empty()) {
            int size = q.size();
            level++;
            while(size--) {
                auto rem = q.front();
                q.pop();

                if(rem == endWord)
                    return level;

                if(vis.find(rem) != vis.end())
                    continue;
                vis.insert(rem);

                for(int i=0; i<wordList.size(); i++) {
                    string nbr = wordList[i];
                    if(vis.find(nbr) != vis.end())
                        continue;
                    if(isNode(rem, nbr)) {
                        q.push(nbr);
                    }
                }
            }
        }

        return 0;
    }
};