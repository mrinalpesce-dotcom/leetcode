class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            int mid = (left + right) / 2;

            // If middle element is greater than right,
            // minimum is in right half
            if(nums[mid] > nums[right])
                left = mid + 1;
            else
                // Minimum is in left half (including mid)
                right = mid;
        }

        return nums[left];
    }
};