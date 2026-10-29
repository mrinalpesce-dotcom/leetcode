class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // If the tree is empty, return an empty answer.
        if (root == nullptr) {
            return {};
        }

        // Store nodes by column -> row -> sorted values.
        map<int, map<int, multiset<int>>> nodes;

        // Queue stores {node, {column, row}}.
        queue<pair<TreeNode*, pair<int, int>>> q;

        // Root starts at column 0 and row 0.
        q.push({root, {0, 0}});

        // Traverse the tree using BFS.
        while (!q.empty()) {

            // Get and remove the front element.
            auto current = q.front();
            q.pop();

            // Extract the node and its coordinates.
            TreeNode* node = current.first;
            int column = current.second.first;
            int row = current.second.second;

            // Insert the node value into the map.
            // Missing columns and rows are created automatically.
            // The map sorts columns and rows.
            // The multiset sorts values at the same position.
            nodes[column][row].insert(node->val);

            // Process the left child.
            if (node->left != nullptr) {
                q.push({
                    node->left,
                    {column - 1, row + 1}
                });
            }

            // Process the right child.
            if (node->right != nullptr) {
                q.push({
                    node->right,
                    {column + 1, row + 1}
                });
            }
        }

        // Store the final answer.
        vector<vector<int>> answer;

        // Visit columns from left to right.
        for (auto& columnEntry : nodes) {

            vector<int> columnValues;

            // Visit rows from top to bottom.
            for (auto& rowEntry : columnEntry.second) {

                // Add sorted values at the current position.
                for (int value : rowEntry.second) {
                    columnValues.push_back(value);
                }
            }

            // Add the completed column to the answer.
            answer.push_back(columnValues);
        }

        return answer;
    }
};