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
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/?envType=study-plan-v2&envId=top-interview-150
// same as preorder and inorder just changed order of calls;
class Solution {
private:
    unordered_map<int, int> mpp;
    int idx;

    TreeNode* build(vector<int>& postorder, int s, int e) {
        if(s>e)
            return nullptr;
        int val = postorder[idx--];
        TreeNode* root = new TreeNode(val);

        int mid = mpp[val];
        root->right = build(postorder, mid+1, e);
        root->left = build(postorder, s, mid-1);
        return root;
    };

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++)
            mpp[inorder[i]]=i;
        idx=postorder.size()-1;
        return build(postorder, 0, inorder.size()-1);
    }
};