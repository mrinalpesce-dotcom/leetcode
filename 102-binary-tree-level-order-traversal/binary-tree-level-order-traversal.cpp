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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);

      while(!q.empty()){
        int size=q.size();

        vector<int> level;
        for(int i=0;i<size;i++){

            TreeNode* node=q.front();
             q.pop();

            
          level.push_back(node->val);

                // Add the left child if it exists
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                // Add the right child if it exists
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // Save the completed level in the answer
            ans.push_back(level);
        }

        return ans;
    }
};





    