class Solution {
public:
    TreeNode* buildtreehelper(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, unordered_map<int,int> &inmap){
        // base case 
        if(prestart > preend || instart > inend){
            return NULL; // handling the leaf node
        }
        TreeNode* rootnode = new TreeNode(preorder[prestart]);
        int rootinorderindex = inmap[rootnode->val];
        int leftsubtreesize = rootinorderindex-instart;
        rootnode->left= buildtreehelper(preorder,prestart+1, prestart+leftsubtreesize,inorder,instart,rootinorderindex-1,inmap);
        rootnode->right = buildtreehelper(preorder,prestart+leftsubtreesize+1,preend,inorder,rootinorderindex+1,inend,inmap);
        return rootnode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inmap;
        for(int i =0;i<inorder.size();i++){
            inmap[inorder[i]]=i;
        }
        return buildtreehelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inmap);
    }
}; 