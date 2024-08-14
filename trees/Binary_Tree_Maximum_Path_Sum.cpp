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

// https://leetcode.com/problems/binary-tree-maximum-path-sum/?envType=study-plan-v2&envId=top-interview-150
// post order traversal hora h... aur max dhoondte rho har subtree mai
class Solution {
public:
    int dfs(TreeNode* root, int& ans) {
        if(!root)
            return 0;
        int l = max(0, dfs(root->left, ans));
        int r = max(0, dfs(root->right, ans));
        ans = max(ans, root->val + l + r);
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        
        dfs(root, ans);
        return ans;
    }
};