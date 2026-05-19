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

class BSTiterator {
        public:
        stack<TreeNode* > st;
        bool reverse;

        void pushall(TreeNode* node){
            while(node){
            st.push(node);
            if(reverse)node = node->right;
            else node = node->left;
            }
        }

        BSTiterator(TreeNode* root , bool reversed){
            reverse = reversed;
            pushall(root);
        }


        int next(){
            TreeNode* top = st.top();
            st.pop();

            if(reverse){
                pushall(top->left);
            }else{
                pushall(top->right);
            }

            return top->val;
        } 

    };
class Solution {
public:
    // vector<int>a;
    // void inorder(TreeNode* root){
    //     if(root==NULL)return;

    //     inorder(root->left);
    //     a.push_back(root->val);
    //     inorder(root->right);
    // }
    bool findTarget(TreeNode* root, int k) {
    //     inorder(root);
    //     int i=0;
    //     int j = a.size()-1;
    //     while(i<j){
    //         if(a[i] + a[j] == k)return true;
    //         if(a[i] + a[j] < k){
    //             i++;
    //         }
    //         else{
    //             j--;
    //         }
    //     }
    // return false;    
        if (!root) return false;
       BSTiterator l(root , false);
       BSTiterator r(root , true);

       int x = l.next();
       int y = r.next();

       while(x < y){
         if(x + y == k)return true;
         if(x + y < k)x = l.next();
         else y = r.next();
       }
       
       return false;
    }
};