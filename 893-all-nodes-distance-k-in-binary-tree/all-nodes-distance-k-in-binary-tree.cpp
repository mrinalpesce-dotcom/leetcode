class Solution {
public:

    // STEP 1: Find the parent of every node
    void findParent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent) {

        queue<TreeNode*> q;

        q.push(root);  // Start BFS from root

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            // If left child exists, store its parent
            if(node->left) {

                parent[node->left] = node;

                q.push(node->left);
            }

            // If right child exists, store its parent
            if(node->right) {

                parent[node->right] = node;

                q.push(node->right);
            }
        }
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        // Stores the parent of each node
        unordered_map<TreeNode*, TreeNode*> parent;

        // Create parent mapping
        findParent(root, parent);


        // STEP 2: Start BFS from the target node

        queue<TreeNode*> q;

        // Prevent visiting the same node again
        unordered_set<TreeNode*> visited;

        q.push(target);

        visited.insert(target);

        int dist = 0;


        // Continue BFS until we reach distance k
        while(!q.empty()) {

            // Number of nodes at the current distance
            int size = q.size();

            // We have reached distance k
            if(dist == k) {
                break;
            }

            // Process all nodes at the current level
            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();


                // 1. Visit left child
                if(node->left && !visited.count(node->left)) {

                    q.push(node->left);

                    visited.insert(node->left);
                }


                // 2. Visit right child
                if(node->right && !visited.count(node->right)) {

                    q.push(node->right);

                    visited.insert(node->right);
                }


                // 3. Visit parent
                if(parent.count(node) && !visited.count(parent[node])) {

                    q.push(parent[node]);

                    visited.insert(parent[node]);
                }
            }

            // Move to the next distance level
            dist++;
        }


        // STEP 3: Collect all nodes at distance k

        vector<int> ans;

        while(!q.empty()) {

            ans.push_back(q.front()->val);

            q.pop();
        }

        return ans;
    }
};