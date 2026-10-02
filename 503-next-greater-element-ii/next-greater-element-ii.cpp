class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int> st;

        int n = nums.size();

        vector<int> ans(n, -1);

        for(int i = 2*n-1; i >= 0; i--) {

            // Get actual index of nums
            int index = i % n;

            // Remove smaller/equal elements
            while(!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }

            // Only store answer during first pass
            if(i < n && !st.empty()) {
                ans[index] = st.top();
            }

            // Put current element into stack
            st.push(nums[index]);
        }

        return ans;
    }
};