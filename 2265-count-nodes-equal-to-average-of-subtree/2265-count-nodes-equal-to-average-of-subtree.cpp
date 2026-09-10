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
class Solution {
public:
    pair<int,pair<int,int>> solve(TreeNode* root){
        if(!root){
            return {0 , {0 , 0}};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);
        int newcnt = left.second.second + right.second.second + 1;
        int newsum = left.second.first + right.second.first + root->val;
        int avg = newsum / newcnt;
        int ans = left.first + right.first;
        if(avg == root->val){
            ans++;
        }
        return {ans , {newsum , newcnt}};
    }
    int averageOfSubtree(TreeNode* root) {
        return solve(root).first;
    }
};