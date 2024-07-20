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
    void inorder(TreeNode * root,vector<int>&nums){
        if(root==NULL){
            return ;
        }
        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>nums;
        int mini = INT_MAX;
        inorder(root,nums);
        for(int i=1;i<nums.size();i++){
            mini = min(mini,nums[i]-nums[i-1]);
        }
        return mini;
    }
};