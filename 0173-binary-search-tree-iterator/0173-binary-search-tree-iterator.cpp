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
class BSTIterator {
public:
    // queue<int>q;
    // void inorder(TreeNode* root){
    //     if(root==NULL){
    //         return;
    //     }
    //     inorder(root->left);
    //     q.push(root->val);
    //     inorder(root->right);
    // }
    stack<TreeNode*>st;

    void pushall(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        // inorder(root);
        pushall(root);
    }
    
    int next() {
        // int x = q.front();
        // q.pop();
        // return x;
        TreeNode* top = st.top();
        st.pop();
        pushall(top->right);
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