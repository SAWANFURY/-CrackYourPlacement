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
void binary(TreeNode *root,string s,vector<string>&path){
    if(root==NULL){
        return ;
    }
    s += to_string(root->val);
    if(root->left==NULL  && root->right == NULL){
        path.push_back(s);
    }
    else{
        s += "->";
        binary(root->left,s,path);
        binary(root->right,s,path);
    }
    
}
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>paths;
        binary(root,"",paths);
        return paths;
    }
};