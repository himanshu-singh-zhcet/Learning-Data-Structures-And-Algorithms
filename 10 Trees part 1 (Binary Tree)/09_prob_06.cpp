#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
class Node{
    public:
    int value;
    Node* left;
    Node* right;
    Node(int data){
    value = data;
    left = right = NULL;
    }
};
vector<int>  reverse_levelorder_traversal(Node* rootnode){
    vector<int> ans;
    if(rootnode==NULL){
        return ans;
    }
    queue<Node*> q;
    stack<Node*> st;
    q.push(rootnode);
    while(!q.empty()){
        int nodes_at_current_level = q.size();
        while(nodes_at_current_level--){
            Node* currnode = q.front();
            q.pop();
            st.push(currnode);
            if(currnode->right){
                q.push(currnode->right);
            }
            if(currnode->left){
                q.push(currnode->left);
            }
        }
        
    }
    while(!st.empty()){
        ans.push_back(st.top()->value);
        st.pop();
    }
    return ans;
}
int main(){
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    vector<int> v = reverse_levelorder_traversal(root);
    for(auto it: v){
        cout<<it<<" ";
    }
return 0;
}