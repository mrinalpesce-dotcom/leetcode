class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        long totalSum = 0;
        long F = 0;
        
      
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
            F += (long)i * nums[i];
        }
        
        long ans = F;
        
        for(int k = 1; k < n; k++){
            F = F + totalSum - (long)n * nums[n - k];
            ans = max(ans, F);
        }
        
        return ans;
    }
};