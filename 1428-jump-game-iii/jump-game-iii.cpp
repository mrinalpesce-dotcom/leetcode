class Solution {
public:
    bool dfs(vector<int>& arr, int i, vector<bool>& visited) {
        // ❌ out of bounds
        if(i < 0 || i >= arr.size()) return false;
        
        // ❌ already visited → avoid infinite loop
        if(visited[i]) return false;
        
        // 🎉 found zero
        if(arr[i] == 0) return true;
        
        // mark visited
        visited[i] = true;
        
        // try both jumps
        return dfs(arr, i + arr[i], visited) || 
               dfs(arr, i - arr[i], visited);
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);
        return dfs(arr, start, visited);
    }
};