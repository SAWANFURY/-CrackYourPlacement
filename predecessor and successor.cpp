/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void pred(Node *root,int key,Node *&pre){
        if(root==NULL){
            return ;
        }
        if(root->key<key){
            pre=root;
            pred(root->right,key,pre);
            return;
        }
        else{
            pred(root->left,key,pre);
            return ;
        }
    }
    
    void suce(Node *root,int key,Node *&suc){
        if(root==NULL){
            return ;
        }
        if(root->key>key){
            suc=root;
            suce(root->left,key,suc);
            return;
        }
        else{
            suce(root->right,key,suc);
            return ;
        }
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre=NULL;
        suc=NULL;
        pred(root,key,pre);
        suce(root,key,suc);
        return;
    }
};