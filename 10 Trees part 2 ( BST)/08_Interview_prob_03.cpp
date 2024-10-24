class Solution {
public:
     
    TreeNode* bstFromPreorderhelper(vector<int> &preorder, int prestart,int preend, vector<int> &inorder, int instart, int inend, unordered_map<int,int> inmap){
         
        if(prestart>preend || instart>inend){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot_idx = inmap[preorder[prestart]];
        int leftsubtree_elements = inroot_idx-instart;

        root->left = bstFromPreorderhelper(preorder,prestart+1,prestart+leftsubtree_elements,inorder,instart,inroot_idx-1,inmap);
        root->right = bstFromPreorderhelper(preorder,prestart+leftsubtree_elements+1,preend,inorder,inroot_idx+1,inend,inmap);

        return root;
    }




    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(),inorder.end());
        unordered_map<int,int> inmap;

        for(int i =0;i<inorder.size();i++){
            inmap[inorder[i]]=i;  //stroing indexed value pair
        }
        
        return bstFromPreorderhelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
    }
};


 // another approch
 
class Solution {
public:

    TreeNode* bstFromPreorderhelper(vector<int>& preorder,int index ,int upperbound)
    {
        // base case 
        if(index>=preorder.size()){
            return NULL;
        }
        if(preorder[index]>=upperbound){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        root->left=bstFromPreorderhelper(preorder,index,root->val);
        root->right=bstFromPreorderhelper(preorder,index,upperbound);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return bstFromPreorderhelper(preorder,index,INT_MAX);
    }
};