class Solution {

    int search(vector<int>& inorder, int left, int right, int val) {

        for(int i = left; i <= right; i++) {
            if(inorder[i] == val) {
                return i;
            }
        }

        return -1;
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,
                    int& preIdx, int left, int right) {

        // Base case
        if(left > right) {
            return nullptr;
        }

        // Create root
        TreeNode* root = new TreeNode(preorder[preIdx]);

        // Move to next preorder element
        preIdx++;

        // Find root in inorder
        int idx = search(inorder, left, right, root->val);

        // Build left subtree
        root->left = build(preorder, inorder, preIdx, left, idx - 1);

        // Build right subtree
        root->right = build(preorder, inorder, preIdx, idx + 1, right);

        return root;
    }

public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int preIdx = 0;

        return build(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};