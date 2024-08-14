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


// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/?envType=study-plan-v2&envId=top-interview-150
// made a map for storing inorder val and finding lst and rst indexes
// using binary search method by inc preorder one by one as it forms tree and using inorder for checking whether we are in valid traversal or not
class Solution {
public:
    unordered_map<int, int> mpp;
    int idx;

    TreeNode* build(vector<int>& preorder, int s, int e) {
        if(s > e)
            return nullptr;
        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);

        int mid = mpp[val];
        root->left = build(preorder, s, mid-1);
        root->right = build(preorder, mid+1, e);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        idx=0;
        return build(preorder, 0, inorder.size()-1);
    }
};