class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {

        vector<int> arr1;
        vector<int> arr2;

        // First element -> arr1
        arr1.push_back(nums[0]);

        // Second element -> arr2
        arr2.push_back(nums[1]);

        // Process remaining elements
        for(int i = 2; i < nums.size(); i++) {

            // Compare only the last elements
            if(arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }

        // Append arr2 to arr1
        for(int x : arr2) {
            arr1.push_back(x);
        }

        return arr1;
    }
};