class Solution {
public:
   bool isvalidbsthelper(TreeNode* root ,long minvalue, long maxvalue){
        // base case 
        if(root == NULL){
            return true;
        }
      // root node value should lie in the range
      if(root->val<=minvalue || root->val>=maxvalue){
          return false;
      }
      // checking the left sub tree and right subtree 
      return isvalidbsthelper(root->left,minvalue,root->val) && isvalidbsthelper(root->right, root->val,maxvalue);
    }
    bool isValidBST(TreeNode* root) {
        return isvalidbsthelper(root,LONG_MIN,LONG_MAX);
    }
};


// another approch

class Solution {
public:
   bool isvalidbsthelper(TreeNode* root ,TreeNode* &prev){
      // base case 
      if(root == NULL){
        return true;
      }
      // left sub tree 
      if(!isvalidbsthelper(root->left,prev)){
        return false;
      }
      // root node
      if(prev!=NULL && root->value<= prev->value){
        return false;
      }
      prev = root;
      // right subtree 
      return isvalidbsthelper(root->right,prev);
    }
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return isvalidbsthelper(root,prev);
    }
};