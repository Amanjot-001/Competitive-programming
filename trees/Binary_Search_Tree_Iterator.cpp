/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// https://leetcode.com/problems/binary-search-tree-iterator/?envType=study-plan-v2&envId=top-interview-150
// at everytime stack with contain elements atmost height of tree
// push root and its lst on stack and when called next pop top and if it has rst then again push that and its lst to stack
// this way instead of inorder a partial inorder is on stack
// S.C => O(h) instead of O(n);
class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        build(root);
    }

    void build(TreeNode* root) {
        while(root) {
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* top = st.top();
        st.pop();
        build(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */