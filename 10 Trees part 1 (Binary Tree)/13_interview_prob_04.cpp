class Solution {
public:
    TreeNode* helper(vector<int> &preorder,int prestart, int preend, vector<int> &postorder, int poststart, int postend,unordered_map<int,int> &postmap){
        if(prestart>preend || poststart>postend){
            return NULL;  // TO HANDLE LEAF NODES 
        }
        
        TreeNode* rootnode = new TreeNode(preorder[prestart]);
        if(prestart==preend ){
            return rootnode;    // it is a leaf node
        }
        
        int leftchildvalue = preorder[prestart+1];
        int leftchildindex = postmap[leftchildvalue];
        int leftsubtreesize = leftchildindex-poststart+1;

        rootnode->left = helper(preorder,prestart+1,prestart+leftsubtreesize,postorder,poststart,leftchildindex,postmap);
        rootnode->right = helper(preorder,prestart+leftsubtreesize+1,preend,postorder,leftchildindex+1,postend-1,postmap);
        return rootnode;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> postmap;
        for(int i = 0;i<postorder.size();i++){
            postmap[postorder[i]]=i;
        }
        return helper(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1,postmap);
    }
};