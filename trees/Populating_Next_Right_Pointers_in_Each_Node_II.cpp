/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/?envType=study-plan-v2&envId=top-interview-150
// simple bfs for level order traversal

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return nullptr;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                Node* rem = q.front();
                q.pop();

                if(size != 0 && !q.empty()) {
                    rem->next = q.front();
                }

                if(rem->left)
                    q.push(rem->left);
                if(rem->right)
                    q.push(rem->right);
            }
        }

        return root;
    }
};