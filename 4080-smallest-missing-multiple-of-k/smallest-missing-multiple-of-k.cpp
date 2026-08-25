class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        set<int> mp;

        for(int i = 1; i <= nums.size() + 1; i++) {
            mp.insert(k * i);
        }

        for(int x : nums) {
            if(mp.find(x) != mp.end()) {
                mp.erase(x);
            }
        }

        return *mp.begin();
    }
};