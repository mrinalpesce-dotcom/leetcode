class Solution {
public:

    // Store the previously visited node
    TreeNode* prev = nullptr;

    bool inorder(TreeNode* root) {

        // Base case: If node is NULL, return true
        if (root == nullptr) {
            return true;
        }

        // Step 1: Traverse the left subtree
        if (!inorder(root->left)) {
            return false;
        }

        // Step 2: Compare current node with previous node
        // Current value must be strictly greater than previous value
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }

        // Update previous node to current node
        prev = root;

        // Step 3: Traverse the right subtree
        if (!inorder(root->right)) {
            return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {

        // Initialize prev before starting traversal
        prev = nullptr;

        // Start inorder traversal
        return inorder(root);
    }
};