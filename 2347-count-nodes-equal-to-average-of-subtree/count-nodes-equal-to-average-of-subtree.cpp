class Solution {
private:
    uint64_t dfs(TreeNode* node, int& ans) {
        if (!node) return 0;

        uint64_t left = dfs(node->left, ans);
        uint64_t right = dfs(node->right, ans);

        int sum = (left >> 32) + (right >> 32) + node->val;
        int count = (uint32_t)left + (uint32_t)right + 1;

        if (node->val == (sum / count)) {
            ans++;
        }

        return ((uint64_t)sum << 32) | (uint32_t)count;
    }

public:
    int averageOfSubtree(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};