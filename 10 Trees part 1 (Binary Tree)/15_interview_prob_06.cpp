class Solution {
public:
    int calculatetime(TreeNode* startnode,unordered_map<TreeNode*,TreeNode*> &parent){
        unordered_set<TreeNode*> infected;
        queue<TreeNode*> q;
        q.push(startnode);
        infected.insert(startnode);
        int time = 0;
        while(!q.empty()){
            int current_level_nodes= q.size();
            bool infectedflag = false;
            while(current_level_nodes--){
                TreeNode* currnode = q.front();
                q.pop();
                if(currnode->left && !infected.count(currnode->left)){
                    infected.insert(currnode->left);
                    infectedflag = true;
                    q.push(currnode->left);
                }
                if(currnode->right && !infected.count(currnode->right)){
                    infected.insert(currnode->right);
                    infectedflag = true;
                    q.push(currnode->right);
                }
                if(parent[currnode] && !infected.count(parent[currnode])){
                    infected.insert(parent[currnode]);
                    infectedflag = true;
                    q.push(parent[currnode]);
                }
            }
            if(infectedflag){
                time++;
            }
        }
        return time;
    }
    TreeNode* makeparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent,int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startnode;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->val == start){
                  startnode = curr;
            }
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return startnode;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startnode = makeparent(root,parent,start);
        return calculatetime(startnode,parent);
    }
};