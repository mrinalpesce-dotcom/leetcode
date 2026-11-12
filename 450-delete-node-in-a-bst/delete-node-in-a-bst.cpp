
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (root == nullptr) {
            return nullptr;
        }

        // Search in the left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        // Search in the right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Node found
        else {

            // Case 1: No left child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: No right child
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Both children exist

            // Find the smallest node in right subtree
            TreeNode* temp = root->right;

            while (temp->left != nullptr) {
                temp = temp->left;
            }

            // Replace current value
            root->val = temp->val;

            // Delete the duplicate node
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};
