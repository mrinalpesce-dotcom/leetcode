class Solution {
public:
vector<int> digits(int num){
    vector<int> temp;
    
    while(num>0){
        int d=num%10;
        temp.push_back(d);
        num=num/10;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            vector<int> part=digits(nums[i]);

            for(int d:part){
                ans.push_back(d);
            }
        }
        return ans;
    }
      
};