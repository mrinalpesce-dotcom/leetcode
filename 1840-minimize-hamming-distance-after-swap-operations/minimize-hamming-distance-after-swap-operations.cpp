class Solution {
public:
    vector<int> parent;

    // Find parent (with path compression)
    int findParent(int x){
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    // Union two nodes
    void unite(int a, int b){
        int pa = findParent(a);
        int pb = findParent(b);
        if(pa != pb) parent[pa] = pb;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);

        // Step 1: initially everyone is its own parent
        for(int i=0;i<n;i++) parent[i] = i;

        // Step 2: connect indices that can swap
        for(auto &p : allowedSwaps)
            unite(p[0], p[1]);

        // Step 3: count values inside each connected component
        unordered_map<int, unordered_map<int,int>> mp;

        for(int i=0;i<n;i++){
            int root = findParent(i);
            mp[root][source[i]]++;
        }

        // Step 4: try to match target values
        int ans = 0;
        for(int i=0;i<n;i++){
            int root = findParent(i);

            if(mp[root][target[i]] > 0)
                mp[root][target[i]]--;   // matched
            else
                ans++;                  // mismatch
        }

        return ans;
    }
};