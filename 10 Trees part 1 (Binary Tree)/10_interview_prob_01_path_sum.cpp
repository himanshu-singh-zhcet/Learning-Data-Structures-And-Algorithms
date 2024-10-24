class Solution {
public:
    int pathsumhelper(TreeNode* root, int targetSum, long int currSum, unordered_map<long int,int> pathcount){
    if(root == NULL){
        return 0;
    }  
    currSum+= root->val;
    int ansCount = pathcount[currSum-targetSum];
    pathcount[currSum]++;
    ansCount += pathsumhelper(root->left,targetSum, currSum, pathcount)+pathsumhelper(root->right,targetSum, currSum, pathcount);
    pathcount[currSum]--;  //while backtracking
    return ansCount;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long int, int> pathcount;
        pathcount[0] =1;
        return pathsumhelper(root,targetSum,0,pathcount);
    }
}; 