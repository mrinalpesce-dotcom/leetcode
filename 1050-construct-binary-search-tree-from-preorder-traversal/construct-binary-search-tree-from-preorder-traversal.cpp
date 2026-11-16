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
TreeNode* insert(TreeNode* root, int x){
    if(root==nullptr){
       return new  TreeNode(x);
    }
    if(x < root->val ){
       root->left= insert(root->left, x);
    }
    if(x > root->val ){
       root->right= insert(root->right, x);
    }

return root;


}


    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=nullptr;
        for(int x:preorder){
            root=insert(root, x);
        }
        return root;
        
    }
};