class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(root == nullptr) {
            return 0;
        }

        // Store node and its position index
        queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});

        unsigned long long ans = 0;

        while(!q.empty()) {

            int n = q.size();

            // Index of first node at this level
            unsigned long long first = q.front().second;

            unsigned long long last = 0;

            for(int i = 0; i < n; i++) {

                auto curr = q.front();
                q.pop();

                TreeNode* node = curr.first;

                // Normalize index to avoid overflow
                unsigned long long index = curr.second - first;

                last = index;

                if(node->left != nullptr) {
                    q.push({node->left, 2 * index + 1});
                }

                if(node->right != nullptr) {
                    q.push({node->right, 2 * index + 2});
                }
            }

            // Calculate width of current level
            ans = max(ans, last + 1);
        }

        return ans;
    }
};