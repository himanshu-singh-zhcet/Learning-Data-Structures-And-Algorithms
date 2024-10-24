class Solution {
public:
    int maxpathsumhelper(TreeNode* root, int &maxsum){
        if(root == NULL){
            return 0;
        }
        int leftmaxsum= max(0,maxpathsumhelper(root->left,maxsum));
        int rightmaxsum= max(0,maxpathsumhelper(root->right,maxsum));
        maxsum = max(maxsum,root->val+leftmaxsum+rightmaxsum);
        return root->val+max(leftmaxsum,rightmaxsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        maxpathsumhelper(root, maxsum);
        return maxsum;
    }
}; 