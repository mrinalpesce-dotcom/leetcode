
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If position is empty, create a new node
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // If value is smaller, go left
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }

        // If value is greater, go right
        else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
