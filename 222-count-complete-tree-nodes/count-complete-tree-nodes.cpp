class Solution {
public:

    // Calculate height by moving only towards left
    int leftHeight(TreeNode* root) {

        int height = 0;

        while(root) {
            height++;
            root = root->left;
        }

        return height;
    }


    // Calculate height by moving only towards right
    int rightHeight(TreeNode* root) {

        int height = 0;

        while(root) {
            height++;
            root = root->right;
        }

        return height;
    }


    int countNodes(TreeNode* root) {

        // If tree is empty, return 0
        if(root == nullptr) {
            return 0;
        }

        // Calculate left and right heights
        int lh = leftHeight(root);
        int rh = rightHeight(root);

        // If both heights are equal,
        // the tree is a perfect binary tree
        if(lh == rh) {
            return (1 << lh) - 1;
        }

        // Otherwise, recursively count left and right subtrees
        return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};