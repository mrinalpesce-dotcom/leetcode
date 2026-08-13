class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();

        // Sort so every subset is generated in the same order
        sort(nums.begin(), nums.end());

        set<vector<int>> uniqueSubsets;

        for (int mask = 0; mask < (1 << n); mask++) {

            vector<int> subset;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            uniqueSubsets.insert(subset);
        }

        vector<vector<int>> ans(
            uniqueSubsets.begin(),
            uniqueSubsets.end()
        );

        return ans;
    }
};