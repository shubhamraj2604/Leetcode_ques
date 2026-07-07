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
    int total = 0;
    int solve(TreeNode* root){
        if(root == NULL){
            return 1;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        if(left == -1 || right == -1){
            total++;
            return 0;
        }
        
        if(left == 0 || right == 0){
            return 1; // this node is covered;
        }
        
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if (solve(root) == -1) {
            total++;
        }

        return total;
    }
};