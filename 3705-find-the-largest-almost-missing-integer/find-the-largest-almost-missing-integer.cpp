class Solution {
public:

    void generate(int index, int k, vector<int>& nums,
                  vector<vector<int>>& ans) {

        // If a complete window of size k is possible
        if (index + k > nums.size()) {
            return;
        }

        vector<int> current;

        // Take k consecutive elements
        for (int i = index; i < index + k; i++) {
            current.push_back(nums[i]);
        }

        ans.push_back(current);

        // Move to the next starting position
        generate(index + 1, k, nums, ans);
    }


    int largestInteger(vector<int>& nums, int k) {

        vector<vector<int>> ans;

        // Generate all subarrays of size k
        generate(0, k, nums, ans);

        // Hashing
        unordered_map<int, int> mp;

        // Count how many windows contain each number
        for (auto& arr : ans) {

            unordered_set<int> seen;

            for (int x : arr) {
                seen.insert(x);
            }

            for (int x : seen) {
                mp[x]++;
            }
        }

        // Find the largest number appearing in exactly one window
        int answer = -1;

        for (auto& it : mp) {
            if (it.second == 1) {
                answer = max(answer, it.first);
            }
        }

        return answer;
    }
};