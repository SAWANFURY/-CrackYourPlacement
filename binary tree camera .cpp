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
    int camera(TreeNode * root,int &cam){
        if(root==NULL) return 1;
        int lh = camera(root->left,cam);
        int rh = camera(root->right,cam);
        if(!(lh&&rh)){cam++; return 2;}
        return max(lh,rh)-1;
    }
    int minCameraCover(TreeNode* root) {
        if(root==NULL) return 0;
        int cam = 0;
        if(!camera(root,cam)){
            cam++;
        }
        return cam;
    }
};