class Solution {

    int search(vector<int>& inorder, int left, int right, int val) {

        for(int i = left; i <= right; i++) {
            if(inorder[i] == val) {
                return i;
            }
        }

        return -1;
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int& postIdx, int left, int right) {

        if(left > right) {
            return nullptr;
        }

        // Take root from the end of postorder
        TreeNode* root = new TreeNode(postorder[postIdx--]);

        // Find root in inorder
        int idx = search(inorder, left, right, root->val);

        // IMPORTANT: Build right subtree first
        root->right = build(inorder, postorder, postIdx,
                            idx + 1, right);

        // Then build left subtree
        root->left = build(inorder, postorder, postIdx,
                           left, idx - 1);

        return root;
    }

public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int postIdx = postorder.size() - 1;

        return build(inorder, postorder, postIdx,
                     0, inorder.size() - 1);
    }
};