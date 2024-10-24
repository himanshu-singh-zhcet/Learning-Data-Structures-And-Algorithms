class Solution {
public:
    TreeNode* lastnode = NULL;
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right=lastnode;
        root->left=NULL;
        lastnode= root;
        return;
    }
}; 