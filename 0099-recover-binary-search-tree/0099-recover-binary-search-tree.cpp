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
    vector<int>ans;
    void inorder(TreeNode* root){
        if(!root)return;

        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }

    void traversal(TreeNode* root , vector<int>&ans , int &index){
        if(!root)return;

        traversal(root->left , ans , index);
        if(root->val != ans[index]){
            root->val = ans[index];
        }
        index++;
        traversal(root->right , ans , index);
    }
    void recoverTree(TreeNode* root) {
          inorder(root);
          sort(ans.begin(), ans.end());
          int index = 0;
          traversal(root , ans , index);
    }
};