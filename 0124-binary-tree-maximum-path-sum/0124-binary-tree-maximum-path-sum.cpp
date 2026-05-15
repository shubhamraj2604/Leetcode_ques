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
    int sum = INT_MIN;
    int sumnode(TreeNode* root){
        if(root==NULL)return 0;
        int leftsum = max(0, sumnode(root->left));
        int rightsum = max(0, sumnode(root->right));
        sum=max(sum,root->val + leftsum + rightsum);

       return root->val + max(leftsum , rightsum);

    }
    int maxPathSum(TreeNode* root) {
        int y = sumnode(root);
        return sum;
    }
};