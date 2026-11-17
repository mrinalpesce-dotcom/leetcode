/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void inorder(TreeNode* root , vector<int> &nums){
    if(root==nullptr){
        return;
    }
    inorder(root->left,nums);
    nums.push_back(root->val);
    inorder(root->right, nums);

  }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums);
        int left=0;
        int right=nums.size()-1;

        while(left< right){
            int currentSum= nums[left] +nums[right];

            if(currentSum==k){
                return true;
            }

            if(currentSum<k){
                left++;
            }
            else{
                right--;
            }
        }
   return false;
        
    }
};