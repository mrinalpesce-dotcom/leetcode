class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n= nums.size();

        unordered_map<int ,vector<int>> mp;
       // stored the numbers of the array
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans= INT_MAX;

        for(auto &p: mp){
            vector<int> &v=p.second;
            if(v.size()>=3){
            for( int i=0;i+2<v.size();i++){
                int diff=2*(v[i+2]-v[i]);
                ans=min(ans, diff);
            }
        }
    }
    return ans == INT_MAX ? -1:ans;

        
    }
};