class NodeInfo{
    public:
    int minvalue;
    int maxvalue;
    int maxcurrentsum;

    NodeInfo(int min,int max,int sum){
        minvalue = min;
        maxvalue = max;
        maxcurrentsum = sum;
    }
};


class Solution {
public:
    int ans = 0;
    NodeInfo maxSumBSThelper(TreeNode* root){
    if(!root){
        return NodeInfo(INT_MAX,INT_MIN,0);
    }
     
    NodeInfo leftsubtree = maxSumBSThelper(root->left);
    NodeInfo rightsubtree = maxSumBSThelper(root->right);

    if(root->val > leftsubtree.maxvalue && root->val< rightsubtree.minvalue){
        // root node forms a bst
        ans = max(ans,leftsubtree.maxcurrentsum+rightsubtree.maxcurrentsum+root->val);
        return NodeInfo(min(leftsubtree.minvalue, root->val), max(rightsubtree.maxvalue,root->val),leftsubtree.maxcurrentsum+rightsubtree.maxcurrentsum+root->val);
    }

    // if root node does not form bst
    return NodeInfo(INT_MIN,INT_MAX,max(leftsubtree.maxcurrentsum,rightsubtree.maxcurrentsum));

    }



    int maxSumBST(TreeNode* root) {
       maxSumBSThelper(root);
       return ans;
    }
};