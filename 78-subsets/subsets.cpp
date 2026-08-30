class Solution {
public:

    void subsets(int index, vector<int>& nums,
                 vector<int>& current,
                 vector<vector<int>>& ans) {

        ans.push_back(current);

        for (int i = index; i < nums.size(); i++) {

            current.push_back(nums[i]);

            subsets(i + 1, nums, current, ans);

            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> current;
        vector<vector<int>> ans;

        subsets(0, nums, current, ans);

        return ans;
    }
};