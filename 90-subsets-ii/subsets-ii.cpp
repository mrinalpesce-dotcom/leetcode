class Solution {
public:

    void solve(int index,
               vector<int>& nums,
               vector<int>& ds,
               vector<vector<int>>& ans) {

     
        ans.push_back(ds);

        // Try every possible next element
        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1])
                continue;

            // Take nums[i]
            ds.push_back(nums[i]);

            solve(i + 1, nums, ds, ans);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, nums, ds, ans);

        return ans;
    }
};