/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    void solve(TreeNode* root, int targetSum, vector<int>& a, int pathsum) {
        if (root == NULL) {
            return;
        }

        a.push_back(root->val);
        pathsum += root->val;
        if (root->left == NULL && root->right == NULL) {
            if (pathsum == targetSum) ans.push_back(a);
        } else {
            solve(root->left, targetSum, a, pathsum);
            solve(root->right, targetSum, a, pathsum);
        }
        a.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int pathsum = 0;
        vector<int> a;
        solve(root, targetSum, a, pathsum);
        return ans;
    }
};