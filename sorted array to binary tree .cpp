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
   TreeNode * sorted(vector<int> nums,int left,int right){
    if(left>right){
        return 0;
    }
    int mid = left+(right-left)/2;
    TreeNode * root1 = new TreeNode(nums[mid]);
    root1->left = sorted(nums,left,mid-1);
    root1->right = sorted(nums,mid+1,right);
    return root1;
   }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left =0;
        int right = nums.size()-1;
        return sorted(nums,left,right);
    }
};